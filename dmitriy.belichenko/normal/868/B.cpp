#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e3;
const int INF = 1e9;
const int MOD = 1e9 + 7;
vector<int> pt;
int n , k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h , m , s , t1 , t2;
    cin >> h >> m >> s >> t1 >> t2;
    h *= 5;
    t1 *= 5;
    t2 *= 5;
    vector<int> a;
    a.pb(h);
    a.pb(m);
    a.pb(s);
    a.pb(t1);
    a.pb(t2);
    sort(a.begin(), a.end());
    for(int i = 0; i < 5; i++) a.pb(a[i]);
    int j = 0;
    while (a[j] != t1) j++;
    if (a[j + 1] == t2)
    {
        cout<<"YES" << "\n";
        return 0;
    }
    while (a[j] != t2) j++;
    if (a[j + 1] == t1)
    {
        cout<<"YES" << "\n";
        return 0;
    }
    cout << "NO" << "\n";
    return 0;
}