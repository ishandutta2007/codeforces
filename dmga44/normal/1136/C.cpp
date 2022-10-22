#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 2005

vector<int> a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,x;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> x;
            a[i+j].push_back(x);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> x;
            b[i+j].push_back(x);
        }

    for(int i=0;i<MAXN;i++)
        sort(a[i].begin(),a[i].end());
    for(int i=0;i<MAXN;i++)
        sort(b[i].begin(),b[i].end());
    bool res=1;
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<a[i].size();j++)
            res&=a[i][j]==b[i][j];
    if(res)
        db("YES")
    else
        db("NO")
    return 0;
}