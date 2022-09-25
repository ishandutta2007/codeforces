#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,ans=0;
	cin >> n;
	string str;
	rep(n){
		cin >> str;
		if(str[0]=='T') ans+=4;
		if(str[0]=='C') ans+=6;
		if(str[0]=='O') ans+=8;
		if(str[0]=='D') ans+=12;
		if(str[0]=='I') ans+=20;
	}
	cout << ans << "\n";
	return 0;
}