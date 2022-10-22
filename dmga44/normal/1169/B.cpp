#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

int f[MAXN];
map<pii,int> fs;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a>b)
            swap(a,b);
        f[a]++;
        f[b]++;
        fs[pii(a,b)]++;
    }

    bool ok=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i]<((m+1)/2))
            continue;
        for(int j=1;j<=n;j++)
            if(i!=j && (f[i]+f[j]-fs[pii(min(i,j),max(i,j))])==m)
                ok=1;
    }
    if(ok)
        db("YES")
    else
        db("NO")

    return 0;
}