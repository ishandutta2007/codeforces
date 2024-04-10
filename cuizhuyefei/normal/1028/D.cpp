#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666,mo=1e9+7;
int res=1,q,val[N],tp[N],p[N],tot;char s[N][9];
bool ck(){
	rep(i,1,tot)tp[i]=tp[i]>=0?tp[i]:0;
//	rep(i,1,tot)printf("%d:%d\n",i,tp[i]);
	priority_queue<int>heap0;
	priority_queue<int,vector<int>,greater<int> >heap1;
	rep(i,1,q){
		if(s[i][1]=='D'){
			if(tp[val[i]])heap1.push(val[i]);else heap0.push(val[i]);
			if(!heap1.empty()&&!heap0.empty()&&heap1.top()<heap0.top())return 0;//WA
		}else{
		//	if(!(!heap1.empty()&&heap1.top()==val[i]||!heap0.empty()&&heap0.top()==val[i]))return 0;
			if(!heap1.empty()&&heap1.top()==val[i])heap1.pop();
			else if(!heap0.empty()&&heap0.top()==val[i])heap0.pop();
			else return 0;
		}
	}
	return 1;
}
int main() {
	read(q);rep(i,1,q)scanf("%s%d",s[i],&val[i]);
	rep(i,1,q)p[++tot]=val[i];sort(p+1,p+tot+1);
	tot=unique(p+1,p+tot+1)-p-1;rep(i,1,tot)tp[i]=-1;
	rep(i,1,q)val[i]=lower_bound(p+1,p+tot+1,val[i])-p;
	Vi a;static bool vis[N];
	rep(i,1,q){
		if(s[i][1]=='D')a.pb(val[i]),vis[val[i]]=1;//WA
		else{
			per(j,SZ(a)-1,0)if(a[j]!=val[i])tp[a[j]]=a[j]>val[i];
			vis[val[i]]=0;a.clear();//WA
		}
	}
//	per(i,SZ(a)-1,0)tp[a[i]]=0;res=SZ(a)+1;//WA WA
	int mx0=0,mn1=1e9;rep(i,1,tot)if(vis[i]&&tp[i]>=0){
		if(tp[i]==1)mn1=min(mn1,i);else mx0=max(mx0,i);
	}
//	printf("dub %d %d\n",mx0,mn1);
//	per(i,SZ(a)-1,0)printf("%d ",a[i]);puts("");
	per(i,SZ(a)-1,0){
		if(a[i]<mx0)tp[a[i]]=0;else if(a[i]>mn1)tp[a[i]]=1;else tp[a[i]]=0,res++;//WA
	}
	rep(i,1,tot)if(tp[i]==-1)res=(res+res)%mo;
	if(ck())printf("%d",res);else printf("0");
	return 0;
}