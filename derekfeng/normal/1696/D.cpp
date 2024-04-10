#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define fi first
#define se second
const int N=250005;
int t,n,p[N];
int l0[N],r0[N],l1[N],r1[N];
int fl0[N],fr0[N],fl1[N],fr1[N];
int dis[N];
int Fl0(int x){return fl0[x]==x?x:fl0[x]=Fl0(fl0[x]);}
int Fr0(int x){return fr0[x]==x?x:fr0[x]=Fr0(fr0[x]);}
int Fl1(int x){return fl1[x]==x?x:fl1[x]=Fl1(fl1[x]);}
int Fr1(int x){return fr1[x]==x?x:fr1[x]=Fr1(fr1[x]);}
queue<int>que;
void upd(int x,int d){
	dis[x]=d,que.push(x);
	fl0[x]=l0[x],fr0[x]=r0[x];
	fl1[x]=l1[x],fr1[x]=r1[x];
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		stack<int>s1,s2,s3,s4;
		for(int i=1;i<=n;i++){
			while(s1.size()&&p[s1.top()]>p[i])s1.pop();
			l0[i]=s1.size()?s1.top():0;s1.push(i);
			while(s2.size()&&p[s2.top()]<p[i])s2.pop();
			l1[i]=s2.size()?s2.top():0;s2.push(i);
		}
		for(int i=n;i;i--){
			while(s3.size()&&p[s3.top()]>p[i])s3.pop();
			r0[i]=s3.size()?s3.top():n+1;s3.push(i);
			while(s4.size()&&p[s4.top()]<p[i])s4.pop();
			r1[i]=s4.size()?s4.top():n+1;s4.push(i);
		}
		for(int i=1;i<=n+1;i++)fl0[i]=fr0[i]=fl1[i]=fr1[i]=i;
		memset(dis,-1,(n+2)<<2);
		que.push(1),dis[1]=0,upd(1,0);
		while(!que.empty()){
			int i=que.front(),L,R,cur;que.pop();
			L=l0[i]+1,R=r0[i]-1;
			cur=Fl1(l1[i]);
			while(cur>=L)upd(cur,dis[i]+1),cur=Fl1(l1[cur]);
			cur=Fr1(r1[i]);
			while(cur<=R)upd(cur,dis[i]+1),cur=Fr1(r1[cur]);
			L=l1[i]+1,R=r1[i]-1;
			cur=Fl0(l0[i]);
			while(cur>=L)upd(cur,dis[i]+1),cur=Fl0(l0[cur]);
			cur=Fr0(r0[i]);
			while(cur<=R)upd(cur,dis[i]+1),cur=Fr0(r0[cur]);
		}
		printf("%d\n",dis[n]);
	}
}