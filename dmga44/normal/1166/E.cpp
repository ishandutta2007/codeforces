#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 10005
#define MAXM 55

bool mk[MAXM][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> m >> n;
    for(int i=0;i<m;i++)
    {
        int x,a;
        cin >> x;
        for(int j=0;j<x;j++)
        {
            cin >> a;
            mk[i][a]=1;
        }
    }

    bool ok=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool ko=0;
            for(int k=0;k<n;k++)
                if(mk[i][k] && mk[j][k])
                    ko=1;
            ok&=ko;
        }
    }

    if(ok)
        db("possible")
    else
        db("impossible")

    return 0;
}