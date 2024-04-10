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
ll n,x,y,m1,m2;
vector<pll> vec1,vec2,vec3,vec4,vec5,vec6;
vector<ll> ans;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep2(i,3,n+1){
		cout << "2 1 2 " << i << endl;
		cin >> x;
		cout << "1 1 2 " << i << endl;
		cin >> y;
		if(x>0){
			vec2.pb(mp(y,i));
		}
		else{
			vec1.pb(mp(y,i));
		}
	}
	sort(all(vec1));
	sort(all(vec2));
	if(!vec1.empty()) m1=vec1.back().second;
	if(!vec2.empty()) m2=vec2.back().second;
	rep(int(vec1.size())-1){
		cout << "2 1 " << m1 << ' ' << vec1[i].second << endl;
		cin >> x;
		if(x>0) vec4.pb(vec1[i]);
		else vec3.pb(vec1[i]);
	}
	rep(int(vec2.size())-1){
		cout << "2 1 " << m2 << ' ' << vec2[i].second << endl;
		cin >> x;
		if(x>0) vec6.pb(vec2[i]);
		else vec5.pb(vec2[i]);
	}
	sort(all(vec3));
	sort(all(vec4));
	sort(all(vec5));
	sort(all(vec6));
	reverse(all(vec4));
	reverse(all(vec6));
	ans.pb(1);
	rep(vec3.size()) ans.pb(vec3[i].second);
	if(!vec1.empty()) ans.pb(m1);
	rep(vec4.size()) ans.pb(vec4[i].second);
	ans.pb(2);
	rep(vec5.size()) ans.pb(vec5[i].second);
	if(!vec2.empty()) ans.pb(m2);
	rep(vec6.size()) ans.pb(vec6[i].second);
	cout << "0 ";
	rep(ans.size()) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}