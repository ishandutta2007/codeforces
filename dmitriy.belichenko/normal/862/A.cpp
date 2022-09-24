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
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e5;
const int INF = 1e9;
ll MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; int x;
    cin >> n >> x;
    int lower = 0, same = 0;
    for(int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if (cur == x) same++;
        else if (cur < x) lower++;
    }
        cout << same + (x - lower) << endl;
}