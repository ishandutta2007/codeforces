#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 105

int res[MAXN][MAXN],mk[MAXN][MAXN],a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,h;
    cin >> n >> m >> h;
    vector<ppi> v;
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
        v.push_back(ppi(pii(a[i],i),0));
    }

    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        v.push_back(ppi(pii(b[i],i),1));
    }

    sort(v.rbegin(),v.rend());

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> mk[i][j];
            mk[i][j]=1-mk[i][j];
        }

    for(int i=0;i<n+m;i++)
    {
        int t=v[i].second;
        int l=v[i].first.second;
        int w=v[i].first.first;
        if(t)
        {
            for(int j=0;j<m;j++)
                if(!mk[l][j] && a[j]>=w)
                {
                    res[l][j]=w;
                    mk[l][j]=1;
                    break;
                }
        }
        else
        {
            for(int j=0;j<n;j++)
                if(!mk[j][l] && b[j]>=w)
                {
                    res[j][l]=w;
                    mk[j][l]=1;
                    break;
                }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!mk[i][j])
                res[i][j]=1;

    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<m;j++)
            cout << res[i][j] << ' ';

    return 0;
}