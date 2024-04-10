#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<int> to(n+1,0);
    vector<int> in(n+1,0);
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin >> a >> b;
        to[a]=b;
        in[b]=1;
    }
    vector<vector<int>> chains;
    vector<int> cid(n+1,-1);
    vector<int> pos(n+1,-1);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            vector<int> c={i};
            while(to[c.back()]!=0) c.push_back(to[c.back()]);
            cnt+=c.size();
            for(int a:c) cid[a]=chains.size();
            for(int j=0;j<(int)c.size();j++) pos[c[j]]=j;
            chains.push_back(c);
        }
    }
    auto out=[](){cout << "0\n";exit(0);};
    if(cnt<n) out();
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0) continue;
        if(cid[i]==cid[p[i]]&&pos[p[i]]<pos[i]) p[i]=0;
    }
    vector<int> v[n+1];
    for(int i=1;i<=n;i++) if(p[i]!=0) v[p[i]].push_back(i);
    int sz=chains.size();
    vector<int> req(sz,0);
    for(int i=1;i<=n;i++) if(p[i]!=0) req[cid[i]]++;
    vector<int> res;
    vector<bool> ini(sz,0);
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(req[cid[i]]==0&&ini[cid[i]]==0)
        {
            q.push(cid[i]);
            ini[cid[i]]=1;
        }
    }
    while(!q.empty())
    {
        int id=q.front();
        q.pop();
        for(int a:chains[id])
        {
            res.push_back(a);
            for(int t:v[a])
            {
                req[cid[t]]--;
                if(req[cid[t]]==0) q.push(cid[t]);
            }
        }
    }
    if((int)res.size()<n) out();
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}