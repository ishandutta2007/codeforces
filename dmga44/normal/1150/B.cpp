#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> ppi;
#define MAXN 55

string a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    bool ok=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='.')
            {
                if(i>=n-2 || j==0 || j==n-1)
                    ok=0;
                else
                {
                    if(a[i+1][j]=='.' && a[i+1][j-1]=='.' && a[i+2][j]=='.' && a[i+1][j+1]=='.')
                    {
                        a[i][j]='#';
                        a[i+1][j+1]='#';
                        a[i+1][j]='#';
                        a[i+1][j-1]='#';
                        a[i+2][j]='#';
                    }
                    else
                        ok=0;
                }
            }
        }
    if(ok)
        db("YES")
    else
        db("NO")

    return 0;
}