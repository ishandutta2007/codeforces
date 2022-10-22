#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int INF=1000000000;

int n, m, p[1000005], d[105][105];

char a[105][105];

vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        cin >> a[i][j];
        if(a[i][j]=='0')
            d[i][j]=INF;
        else d[i][j]=1;
    }

    for(int i=0;i<n;i++)
        d[i][i]=0;

    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> p[i];
        p[i]--;
    }

    for(int u=0;u<n;u++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=min(d[i][j], d[i][u]+d[u][j]);

    v.push_back(0);

    for(int i=1; i<m; i++)
    {
        if(d[p[v[v.size()-1]]][p[i]] != i-v[v.size()-1])
            v.push_back(i-1);
    }

    v.push_back(m-1);

    cout << v.size() << endl;
    for(auto to:v)
        cout << p[to]+1 << ' ';
}