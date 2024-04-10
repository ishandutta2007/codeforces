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

bool check(char x)
{
    return x >= 'A' && x <= 'Z';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    int r = 0;
    for (int l = -1; l < n; l )
    {
        r = l + 1;
        for (; !check(s[r]) && r <= n - 1; r++);
        set <char> HAS;
        for (int i = l + 1; i < r; i++)
        {
            HAS.insert(s[i]);
        }
        cnt = max(cnt, (ll) HAS.size());
        if(check(s[l]))
        l = r;
        else l = r;
    }
    cout << cnt << "\n";
    return 0;
}