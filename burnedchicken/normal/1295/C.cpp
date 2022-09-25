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
int t,n,x,num,a[200005],Max,Min,ans;
string str1,str2;
vector<int> vec[26];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> str1 >> str2;
		rep(26) vec[i].clear();
		rep(str1.size()) vec[str1[i]-'a'].pb(i);
		ans=0;
		x=-1;
		rep(str2.size()){
			if(vec[str2[i]-'a'].empty()){
				ans=-2;
				break;
			}
			if(vec[str2[i]-'a'].back()<=x){
				ans++;
				x=-1;
			}
			x=*upper_bound(all(vec[str2[i]-'a']),x);
		}
		cout << ans+1 << '\n';
	}
	return 0;
}