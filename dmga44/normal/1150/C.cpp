#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

int a[MAXN],f[2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
        f[a[i]]++;
    }

    if(!f[0])
    {
        for(int i=0;i<n;i++)
            cout << 2 << ' ';
    }
    else
    {
        if(!f[1])
        {
            for(int i=0;i<n;i++)
                cout << 1 << ' ';
        }
        else
        {
            f[0]--;
            f[1]--;
            cout << 2 << ' ' << 1 << ' ';
            for(int i=0;i<f[1];i++)
                cout << 2 << ' ';
            for(int i=0;i<f[0];i++)
                cout << 1 << ' ';
        }
    }

    return 0;
}