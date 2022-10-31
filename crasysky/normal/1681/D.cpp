#include <bits/stdc++.h>
#define ll unsigned long long
#define pr pair<ll,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,D; ll pw9[100],pw[100];
void dfs(ll x,int t){
	if (x<pw[n-1]/pw9[D-t]) return;
	if (x>=pw[n-1]){ cout<<D<<endl; exit(0); }
	bool tg[10]; for (int i=2;i<=9;++i) tg[i]=0;
	for (ll y=x;y;y/=10) tg[y%10]=1;
	for (int i=9;i>=2;--i) 
		if (tg[i]){
			if (x>pw[n-1]/i){ cout<<D<<endl; exit(0); }
			dfs(x*i,t+1);
		}
}
int main(){
	ll x; cin>>n>>x;
	bool f=false; for (ll v=x;v;v/=10) if (v%10>1) f=true;
	pw9[0]=1; for (int i=1;i<=19;++i) pw9[i]=pw9[i-1]*9;
	pw[0]=1; for (int i=1;i<=19;++i) pw[i]=pw[i-1]*10;
	for (int i=20;i<=50;++i) pw9[i]=pw[n-1];
	if (!f){ cout<<-1<<endl; return 0; }
	for (D=1;;++D) dfs(x,0);
	return 0;
}