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
    int n , x;
    cin >> n >> x;
    if(n == 1)
    {
        cout << "YES" << "\n";
        cout << x << "\n";
        return 0;
    }
    if(n == 2)
    {
        if(x == 0)
        cout << "NO"<< "\n";
        else cout << "YES\n" << x << " " << 0 << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    if( n % 2)
    {
        for(int i = 0; i < n - 3; i++)
        {
            cout << i << " ";
            x = x ^ i;
        }
        int a = 1 << 18;
        int b = 1 << 19;
        cout << a << " " << (b ^ x) << " " << (a ^ b) << " ";
    }
    if( n % 2 == 0)
    {
        for(int i = 0; i < n - 3; i++)
        {
            cout << i << " ";
            x = x ^ i;
        }
        int a = 1 << 18;
        int b = 1 << 19;
        cout << (a ^ x )<< " " << b << " " << (a ^ b) << " ";
       // cout << 0 << "\n";
    }
    return 0;
}