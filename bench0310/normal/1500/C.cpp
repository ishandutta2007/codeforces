#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector a(n,vector(m,int(0)));
    vector b(n,vector(m,int(0)));
    vector<pair<vector<int>,int>> one,two;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >> a[i][j];
        one.push_back({a[i],i});
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >> b[i][j];
        two.push_back({b[i],i});
    }
    ranges::sort(one);
    ranges::sort(two);
    vector<int> p(n);
    vector<int> pos(n);
    for(int i=0;i<n;i++)
    {
        if(one[i].first!=two[i].first)
        {
            cout << "-1\n";
            exit(0);
        }
        p[one[i].second]=two[i].second;
        pos[two[i].second]=one[i].second;
    }
    vector<int> blocked(m,0);
    vector<int> forced(n-1,0); //is a swap required
    vector<int> bad[n-1];
    vector good(n-1,vector(m,int(0)));
    for(int i=0;i+1<n;i++)
    {
        int x=pos[i];
        int y=pos[i+1];
        forced[i]=(x>y);
        for(int j=0;j<m;j++)
        {
            if(a[x][j]<a[y][j]) good[i][j]=1;
            if(a[x][j]>a[y][j])
            {
                bad[i].push_back(j);
                blocked[j]++;
            }
        }
    }
    vector<int> processed(n-1,0);
    queue<int> q;
    for(int j=0;j<m;j++) if(blocked[j]==0) q.push(j);
    vector<int> res;
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        res.push_back(c);
        for(int i=0;i+1<n;i++)
        {
            if(good[i][c]&&!processed[i])
            {
                processed[i]=1;
                for(int j:bad[i]) if((--blocked[j])==0) q.push(j);
            }
        }
    }
    bool ok=1;
    for(int i=0;i+1<n;i++) ok&=(!forced[i]||processed[i]);
    if(ok)
    {
        ranges::reverse(res);
        cout << res.size() << "\n";
        for(int c:res) cout << c+1 << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}