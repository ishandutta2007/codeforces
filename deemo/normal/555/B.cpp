#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
struct Dis{
    ll mini , maxi;
    ll num;
};

bool help(Dis a , Dis b){
    if (a.mini < b.mini)	return	 true;
    if (a.mini == b.mini && a.maxi < b.maxi)    return	true;
    if (a.mini == b.mini && a.maxi == b.maxi && a.num < b.num)	 return  true;
    return  false;
}

ll n , m;
const ll max_n = 2 * 1e5 + 200;
set<ll>	   st;
vector<pair<ll , ll>> vec;
vector<Dis> gec;
ll ans[max_n];
map<ll , vector<ll>>  mp;
map<ll , int>	  mark;

int main(){
    cin >> n >> m;
    ll a , b;
    for (ll i = 0 ; i < n ; i++){
	 cin >> a >> b;
	 vec.push_back({a , b});
    }
    for (ll i = 0 ; i < m ; i++){
	 cin >> a;
	 mp[a].push_back(i + 1);
	 st.insert(a);
	 mark[a] = mark[a] + 1;
    }
    Dis temp;
    for (ll i = 0 ; i < n - 1 ; i++){
	 temp.mini = (vec[i + 1].first - vec[i].second);
	 temp.maxi = (vec[i + 1].second - vec[i].first);
	 temp.num = i + 1;
	 gec.push_back(temp);
    }
    sort(gec.begin() , gec.end() , help);
    reverse(gec.begin() , gec.end());
    
    for (ll i = 0 ; i < gec.size() ; i++){
	 if (st.upper_bound(gec[i].maxi) == st.begin()){
	     cout << "No" << endl;
	     return  0;
	 }
	 set<ll>::iterator it = st.upper_bound(gec[i].maxi);
	 it--;
	 ll t = *it;
	 if (t < gec[i].mini){
	     cout << "No" << endl;
	     return  0;
	 }
	 ans[gec[i].num] = mp[t][mp[t].size() - 1];
	 mp[t].pop_back();
	 mark[t] -= 1;
	 if (mark[t] == 0)	st.erase(t);
    }
    cout << "Yes" << endl;
    for (ll i = 1 ; i < n ; i++){
	 if (i == n - 1) cout << ans[i] << endl;
	 else	  cout << ans[i] << " ";
    }
    return 0;
}