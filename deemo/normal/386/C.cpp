/*
    I found myself in Wonderland
    Get back on my feet again..
*/

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
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

ll ans[200];
string s;
bool mark[200];
set<ll>    st;
ll save[200];

int main(){
    read_fast;
    cin >> s;
    set<ll>::iterator it1 , it2;
    st.insert(-1);
    st.insert(s.size());
    for (ll i = 0 ; i < s.size() ; i++){
	 if (mark[s[i]]) st.erase(save[s[i]]);
	 save[s[i]] = i;
	 mark[s[i]] = 1;
	 st.insert(i);
	 
	 it1 = st.begin();
	 for (ll j = st.size() - 2 ; j > 0 ; j--){
	     it2 = it1;
	     it2++;
	     ans[j] += *it2 - *it1;
	     it1 = it2;
	 }
    }
    cout << st.size() - 2 << endl;
    for (ll i = 1 ; i <= st.size() - 2 ; i++)
	 cout << ans[i] << endl;
    return 0;
}