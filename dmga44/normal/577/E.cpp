#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 1000005

int a[MAXN],b[MAXN];
vector<ppi> buck[1005];

int dist(int i,int j)
{
    return abs(a[i]-a[j])+abs(b[i]-b[j]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        buck[a[i]/1000].push_back(ppi(pii(b[i],a[i]),i+1));
    }

    for(int i=0;i<1005;i++)
        sort(buck[i].begin(),buck[i].end());

    for(int i=0;i<1005;i++)
    {
        if(i&1)
        {
            for(auto y : buck[i])
                cout << y.second << ' ';
        }
        else
        {
            for(int j=buck[i].size()-1;j>=0;j--)
                cout << buck[i][j].second << ' ';
        }
    }

    return 0;
}