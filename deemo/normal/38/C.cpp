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

int main(){
    int n , mini;
    vector<int> vec;
    cin >> n >> mini;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.pb(temp);
    }
    sort(vec.begin() , vec.end());
    int ans = 0;
    for (int i = mini ; i <= 100 ; i++){
	 int t = 0;
	 for (int j = 0 ; j < n ; j++)
	     t += vec[j] / i;
	 t *= i;
	 ans = max(ans , t);
    }
    cout << ans << endl;
    return 0;
}