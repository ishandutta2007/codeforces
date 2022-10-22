#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int f[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int xxx;
    cin >> xxx;
    string n;
    cin >> n;
    for(int i=1;i<=9;i++)
        cin >> f[i];
    bool ok=0,ya=0;
    for(int i=0;i<n.size();i++)
    {
        if(!ok)
        {
            int x=n[i]-'0';
            if(f[x]>x)
            {
                n[i]='0'+f[x];
                ok=1;
            }
        }
        else if(!ya)
        {
            int x=n[i]-'0';
            if(f[x]<x)
                ya=1;
            else
                n[i]='0'+f[x];
        }
    }
    db(n)

    return 0;
}