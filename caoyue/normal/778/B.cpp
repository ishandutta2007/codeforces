#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e3+7;
const int M=1e3+7;
const int INF=1e9+7;
map<string,int>mp;
int n,m;
struct num{
	int a,b,op;
	int q[M];
}t[N];
int ans[N],f[N],ans2[N];
bool vis[N];
string d;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		cin>>d;
		mp[d]=i;
		cin>>d;
		cin>>d;
		if(!mp.count(d)&&d[0]!='?')rep0(j,m)t[i].q[j+1]=d[j]-'0',t[i].op=0;
		else{
			if(d[0]=='?')t[i].a=-1;
			else t[i].a=mp[d];
			cin>>d;
			if(d[0]=='A')t[i].op=1;
			if(d[0]=='O')t[i].op=2;
			if(d[0]=='X')t[i].op=3;
			cin>>d;
			if(d[0]=='?')t[i].b=-1;
			else t[i].b=mp[d];
		}
	}
	rep(i,m){
		int a0=0,a1=0;
		rep(j,n){
			if(!t[j].op)f[j]=t[j].q[i];
			else{
				int av,bv;
				if(~t[j].a)av=f[t[j].a];else av=0;
				if(~t[j].b)bv=f[t[j].b];else bv=0;
				if(t[j].op==1)f[j]=av&bv;
				if(t[j].op==2)f[j]=av|bv;
				if(t[j].op==3)f[j]=av^bv;
			}
			a0+=f[j];
		}
		rep(j,n){
			if(!t[j].op)f[j]=t[j].q[i];
			else{
				int av,bv;
				if(~t[j].a)av=f[t[j].a];else av=1;
				if(~t[j].b)bv=f[t[j].b];else bv=1;
				if(t[j].op==1)f[j]=av&bv;
				if(t[j].op==2)f[j]=av|bv;
				if(t[j].op==3)f[j]=av^bv;
			}
			a1+=f[j];
		}
		if(a0<a1)ans[i]=0,ans2[i]=1;
		else if(a0>a1) ans[i]=1,ans2[i]=0;
		else ans[i]=ans2[i]=0;
	}
	rep(i,m)printf("%d",ans[i]);
	printf("\n");
	rep(i,m)printf("%d",ans2[i]);
	printf("\n");
	return 0;
}