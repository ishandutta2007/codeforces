#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,a[N],p[N],stck[N],tp,l[N],r[N],s[N],ans;
struct node{int x,lc,rc,f;}t[N];
void find(int x,int val,int l,int r){
	if(p[val-t[x].x]>=l&&p[val-t[x].x]<=r)ans++;
	if(t[x].lc)find(t[x].lc,val,l,r);
	if(t[x].rc)find(t[x].rc,val,l,r);
}
void solve(int x){
	s[x]=1;l[x]=x;r[x]=x;
	if(t[x].lc)solve(t[x].lc),l[x]=l[t[x].lc],s[x]+=s[t[x].lc];
	if(t[x].rc)solve(t[x].rc),r[x]=r[t[x].rc],s[x]+=s[t[x].rc];
	if(!t[x].lc||!t[x].rc)return;
	if(s[t[x].lc]<s[t[x].rc])find(t[x].lc,a[x],x+1,r[x]);
	else find(t[x].rc,a[x],l[x],x-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=i;
	t[0].x=n+1;
	for(int i=1;i<=n;i++){
		int la=0;
		while(a[i]>t[stck[tp]].x)la=stck[tp--];
		t[i]=(node){a[i],la,0,stck[tp]};
		t[stck[tp]].rc=t[la].f=i;
		stck[++tp]=i;
	}
	solve(0);printf("%d\n",ans);
	return 0;
}