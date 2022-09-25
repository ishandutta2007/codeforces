#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
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
 
const ll Mod=1000000007,Mod2=998244353;
int q,l,r,cnt;
string str;
vector<int> vec[26];
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> str >> q;
	rep(str.size()) vec[str[i]-'a'].pb(i);
	while(q--){
		cin >> l >> r;
		l--,r--;
		if(l==r||str[l]!=str[r]){
			cout << "Yes\n";
			continue;
		}
		cnt=0;
		rep(26){
			if(vec[i].empty()) continue;
			if(vec[i].back()<l) continue;
			if((*lower_bound(all(vec[i]),l))<=r) cnt++;
		}
		if(cnt>=3) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}