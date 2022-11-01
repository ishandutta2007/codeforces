#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> one(n+1,vector<int>(k,0));
    auto mx=[](int &a,int b){a=max(a,b);};
    for(int i=1;i<=n;i++)
    {
        vector<vector<int>> now(m+1,vector<int>(k,0));
        for(int j=1;j<=m;j++)
        {
            int a;
            cin >> a;
            vector<vector<int>> nxt=now;
            for(int x=0;x<m;x++)
            {
                for(int y=0;y<k;y++)
                {
                    if((now[x][y]%k)==y) mx(nxt[x+1][(y+a)%k],now[x][y]+a);
                }
            }
            now=nxt;
        }
        for(int x=0;x<=m/2;x++) for(int y=0;y<k;y++) if((now[x][y]%k)==y) mx(one[i][y],now[x][y]);
    }
    vector<int> now(k,0);
    for(int i=1;i<=n;i++)
    {
        vector<int> nxt=now;
        for(int x=0;x<k;x++) for(int y=0;y<k;y++) if((now[x]%k)==x&&(one[i][y]%k)==y) mx(nxt[(x+y)%k],now[x]+one[i][y]);
        now=nxt;
    }
    cout << now[0] << "\n";
    return 0;
}