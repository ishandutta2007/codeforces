
#include<cstring>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie();
    cout.tie(0);
    int n , ans = 0, sum = 0;;
    map<int, int> m;
    cin >> n;
    int t = 0;
    cin >> t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int l = max(0, x - i - 1);
        int r = t - i;
        r--;
        if (r >= l - 1)
        {
            m[l]++;
            m[r]--;
        }
    }
    
    for (auto x : m)
    {
        sum += x.second;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;

}