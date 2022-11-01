#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<pair<int,int>> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<long long> d(n+1,(1ll<<60));
    vector<int> p(n+1,0);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    q.push({0,1});
    d[1]=0;
    while(!q.empty())
    {
        auto [da,a]=q.top();
        q.pop();
        if(d[a]<da) continue;
        for(auto [to,w]:v[a])
        {
            if(da+w<d[to])
            {
                d[to]=da+w;
                p[to]=a;
                q.push({d[to],to});
            }
        }
    }
    vector<int> res;
    res.push_back(n);
    while(res.back()!=1&&res.back()!=0) res.push_back(p[res.back()]);
    reverse(res.begin(),res.end());
    if(res[0]!=0) for(int i=0;i<(int)res.size();i++) printf("%d%c",res[i]," \n"[i==(int)res.size()-1]);
    else printf("-1\n");
    return 0;
}