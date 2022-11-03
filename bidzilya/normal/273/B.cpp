#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll mod;
int n;
pii m[222222];

ll f(int a, int b)
{
    int x = 2*b + a;
    ll res = 1;
    for (int i=2; i<=x; i++)
    {
        int mn = i;
        while (mn%2==0 && b>0)
        {
            mn /= 2;
            b--;
        }
        res = (res*mn)%mod;
    }
    return res;
}

bool cmp(const pii& x, const pii& y)
{
    return (x.first < y.first ||
            (x.first == y.first && x.second < y.second));
}

int main()
{
    cin >> n;
    for (int j=0; j<2; j++)
        for (int i=0; i<n; i++)
        {
            cin >> m[j*n+i].first;
            m[j*n+i].second = i;
        }
    cin >> mod;
    sort(m, m+2*n, cmp);
    int a=1, b=0;
    ll ans = 1;
    for (int i=1; i<2*n; i++)
        if (m[i].first != m[i-1].first)
        {
            ans = (ans*f(a,b))%mod;
            a = 1;
            b = 0;
        }
        else
        {
            if (m[i].second == m[i-1].second)
            {
                a--;
                b++;
            }else
                a++;
        }
    ans = (ans*f(a,b))%mod;
    cout << ans << endl;
    return 0;
}