#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool bad[10][10][10][10];
int res=0;
vector<int> now(10,0);
int k;

void solve(int x)
{
    if(x==k+1)
    {
        bool ok=1;
        for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) ok&=(bad[i][now[i]][j][now[j]]==0);
        res+=ok;
    }
    else
    {
        for(int i=1;i<=x;i++)
        {
            now[x]=i;
            solve(x+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m >> k;
    vector<array<int,2>> v[n+1];
    vector<array<int,2>> vr[n+1];
    vector<int> w(m,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b >> w[i];
        v[a].push_back({b,i});
        vr[b].push_back({a,i});
    }
    vector<int> out(m,0);
    vector<int> ord(m,0);
    for(int i=1;i<=n;i++)
    {
        vector<array<int,2>> tmp; //w,id
        for(auto [to,id]:v[i])
        {
            out[id]=v[i].size();
            tmp.push_back({w[id],id});
        }
        sort(tmp.begin(),tmp.end());
        for(int j=0;j<(int)tmp.size();j++) ord[tmp[j][1]]=j+1;
    }
    for(int a=0;a<=9;a++) for(int b=0;b<=9;b++) for(int c=0;c<=9;c++) for(int d=0;d<=9;d++) bad[a][b][c][d]=0;
    for(int i=1;i<=n;i++)
    {
        map<array<int,2>,int> cnt;
        for(auto [from,id]:vr[i]) cnt[{out[id],ord[id]}]++;
        for(auto [from,id]:vr[i])
        {
            for(auto [one,c]:cnt)
            {
                auto [a,b]=one;
                if(c>1||(c==1&&(a!=out[id]||b!=ord[id]))) bad[out[id]][ord[id]][a][b]=1;
            }
        }
    }
    solve(1);
    cout << res << "\n";
    return 0;
}