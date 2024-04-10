#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=6e5+7;
const int INF=1e9+7;
int n;
char s[N];
int a[N],sm[N],t[N],lf[N];
set<int>S[N*2];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,n)a[i]=a[i+n]=(s[i]=='(')?1:-1;
	rep(i,2*n)sm[i]=sm[i-1]+a[i];
	if(sm[n]!=0){
		puts("0");
		puts("1 1");
		return 0;
	}
	int ans=0,l=1,r=1,mn=INF;
	rep(i,n)mn=min(mn,sm[i]);
	rep(i,n)ans+=(sm[i]==mn);
	int qa=ans;
	for(int i=2*n;i;i--){
		if(sm[i]>mn+2)continue;
		S[sm[i]+N].insert(i);
		lf[i]=S[sm[i]+N].size();
	}
	for(int i=n;i;i--){
		if(a[i+1]==1)continue;
		set<int>::iterator gg=S[mn+N].upper_bound(n+i);
		gg--;
		int t=*gg;
		set<int>::iterator hh=S[mn+1+N].upper_bound(n+i);
		int as=lf[t+1]-(hh==S[mn+1+N].end()?0:lf[*hh]);
		if(as>ans){
			ans=as;
			l=i%n+1;
			r=t%n+1;
		}
		set<int>::iterator vv =S[mn+1+N].upper_bound(i+n);
		vv--;
		int k=*vv;
		if(k!=i+n){
			set<int>::iterator uu=S[mn+2+N].upper_bound(n+i);
			int as=qa+lf[k+1]-(uu==S[mn+2+N].end()?0:lf[*uu]);
			if(as>ans){
				ans=as;
				l=i%n+1;
				r=k%n+1;
			}
		}
	}
	cout<<ans<<endl;
	cout<<l<<" "<<r<<endl;
	return 0;
}