
#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  5005;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    vector<int> res;
    for(int i = 2; i <= n; i+=2)
    {
        res.pb(i);
    }
    for(int i = 1; i <= n; i+=2)
    {
        res.pb(i);
    }
    for(int i = 2; i <= n; i+=2)
    {
        res.pb(i);
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}