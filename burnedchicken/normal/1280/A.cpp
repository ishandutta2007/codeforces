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
	int t,x,y;
	ll ans;
	cin >> t;
	string str,str1;
	while(t--){
		cin >> x >> str;
		ans=str.size();
		rep2(i,1,x+1){
			y=str[i-1]-'0';
			ans=(((ans-i+Mod)*y)%Mod+i)%Mod;
			if(y==1) continue;
			if(str.size()<x){
				str1=str.substr(i,str.size()-i);
				rep1(j,y-1) str+=str1;
			}
			if(str.size()>x) str.erase(str.begin()+x,str.end());
		}
		cout << ans << "\n";
	}
	return 0;
}