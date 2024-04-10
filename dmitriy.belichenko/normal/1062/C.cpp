#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll MOD = 1e9 + 7;
ll p[N] , a[N];
ll q , n;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    p[0] = 1;
    for(int i = 0; i < n; i++)
    {
        a[i + 1] += a[i];
        if(s[i] == '1')
        {
            a[i + 1]++;
        }
        p[i + 1] = (p[i] * 2) % MOD;
    }
    while(q--)
    {
        int l , r;
        cin >> l >> r;
        cout << (MOD + MOD + p[r-l+1] - p[r-l + 1 - a[r]+ a[l-1]]) % MOD<<"\n";
    }
    return 0;
}