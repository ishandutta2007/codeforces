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

const int max_n = 1e5 + 10;
const int INF = 1e9+7;

int n;
vector<int> vec(max_n);
int d[max_n];

int main(){
    read_fast;
    cin >> n;
    int ans = 0;
    for (int i = 0 ; i < n ; i++)	 cin >> vec[i];
    fill(d , d + n , INF);
    d[0] = d[n - 1] = 1;
    for (int i = 1 ; i < n ; i++){
	 d[i] = min(d[i] , d[i - 1] + 1);
	 d[i] = min(d[i] , vec[i]);
    }
    for (int i = n - 2 ; i >= 0 ; i--)
	 d[i] = min(d[i] , d[i + 1] + 1);
    for (int i = 0 ; i < n ; i++)
	 ans = max(ans , d[i]);
    cout << ans << endl;
    return 0;
}