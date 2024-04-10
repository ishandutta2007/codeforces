#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
signed main(){
	ll k,l,r,t,x,y; cin>>k>>l>>r>>t>>x>>y;
	r-=l,k-=l;
	if (y<x){
		if (k+y<=r) k+=y;
		puts((k-x)/(x-y)>=t-1?"Yes":"No");
	}
	else{
		if (r>=x+y) puts("Yes");
		else{
			rep(i,0,x){
				if (k+y<=r) k+=y;
				if (k<x){ puts("No"); return 0; }
				if (k/x>=t) break; else t-=k/x;
				k%=x;
			}
			puts("Yes");
		}
	}
	return 0;
}