#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+7;

int n,m;
vector<int>g[N];

int main()
{
  //  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
        s.insert(i);
    }
    vector<int>a;
    for(int i=1;i<=n;i++)
    {
        if(s.count(i))
        {
            int cnt=0;
            s.erase(i);
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                cnt++;
                vector<int>cur;
                int nod=q.front(); q.pop();
                auto it=s.begin();
                int p=0;
                while(it!=s.end())
                {
                    while(p+1<g[nod].size() && g[nod][p]<*it)
                    {
                        p++;
                    }
                    if(p>=g[nod].size() || g[nod][p]!=*it)
                    {
                        cur.push_back(*it);
                    }
                    it++;
                }
                for(auto &it:cur)
                {
                    s.erase(it);
                    q.push(it);
                }
            }
            a.push_back(cnt);
        }
    }
    cout<<a.size()<<"\n";
    sort(a.begin(),a.end());
    for(auto &x:a)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

3 1
1 2

**/