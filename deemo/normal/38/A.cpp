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

int a[200];

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 1 ; i <= n - 1 ; i++)
	 cin >> a[i];
    int c , d;
    cin >> c >> d;
    ll ans = 0;
    while (c != d){
	 ans += a[c];
	 c++;
    }
    cout << ans << endl;
    return 0;
}