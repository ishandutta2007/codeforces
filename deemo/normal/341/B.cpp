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

const int max_n = 2e5 + 10;

int n , temp;
vector<int> ans;

int main(){
    read_fast;  
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
    	 int pos = lower_bound(ans.begin() , ans.end() , temp) - ans.begin();
	 if (pos == ans.size())  ans.pb(temp);
	 else	  ans[pos] = temp;
    }
    cout << ans.size() << endl;
    return 0;
}