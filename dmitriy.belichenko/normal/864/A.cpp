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

const int N = 500;
ll INF = 1LL << 62;
const int MOD = 1e9 + 7;
int tin[N];
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        a[p]++;
    }
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (a[i] == a[j] && a[i] + a[j] == n)
            {
                cout << "YES\n" << i << " " << j << "\n";
                return 0;
            }
        }
   cout << "NO" << "\n";
    return 0;
}