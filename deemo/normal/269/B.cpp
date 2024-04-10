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
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

const int max_n = 5200;

int n , m;
vector<pair<double , int>> vec;
vector<int> ans;

int main(){ 
    read_fast;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
	 pair<double , int> t;	cin >> t.second >> t.first;
	 vec.push_back(t);
    }
    sort(vec.begin() , vec.end());
    for (int i = 0 ; i < n ; i++){
	 int pos = upper_bound(ans.begin() , ans.end() , vec[i].second) - ans.begin();
	 if (pos == ans.size())  ans.pb(vec[i].second);
	 else	  ans[pos] = vec[i].second;
    }
    cout << n - ans.size() << endl;
    return 0;
}