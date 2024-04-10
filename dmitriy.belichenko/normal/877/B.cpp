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
    string s;
    cin >> s;
    string t = "";
    int ans = 0;
    int n = s.size();
    vector<int> pref(n + 1);
    vector<int> pf(n + 1);
    for(int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + (s[i] == 'a');
    }
    for(int i = 0; i < n; i++)
    {
        pf[i + 1] = pf[i] + (s[i] == 'b');
    }
    for(int l = 0; l <= n; l++)
    {
        for(int r = l; r <= n; r++) //[0:l) [l:r) [r:
        {
            int cnt1 = pref[l];
            int cnt2 = pref[n] - pref[r];
            int cnt3 = pf[r] - pf[l];
            ans = max(cnt1 + cnt2 + cnt3 , ans);
        }
    }
    cout << ans << "\n";
}