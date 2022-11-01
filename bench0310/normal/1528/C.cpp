#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<int> va[N+1];
vector<int> vb[N+1];
int tcnt=1;
vector<int> tin(N+1,0);
vector<int> tout(N+1,0);
int res=0;
set<array<int,2>> s;

void dfsb(int a)
{
    tin[a]=tcnt++;
    for(int to:vb[a]) dfsb(to);
    tout[a]=tcnt-1;
}

void dfsa(int a)
{
    int l=tin[a];
    int r=tout[a];
    auto it=s.lower_bound({l,r});
    array<int,2> rm={0,0};
    array<int,2> add={0,0};
    if(it!=s.end()&&(*it)[1]<=r){} //there's already a better node
    else if(it!=s.begin())
    {
        it--;
        if((*it)[0]<=l&&r<=(*it)[1])
        {
            rm=(*it);
            s.erase(it);
        }
        add={l,r};
        s.insert({l,r});
    }
    else
    {
        add={l,r};
        s.insert({l,r});
    }
    res=max(res,(int)s.size());
    for(int to:va[a]) dfsa(to);
    if(add[0]!=0) s.erase(add);
    if(rm[0]!=0) s.insert(rm);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=2;i<=n;i++)
        {
            int p;
            cin >> p;
            va[p].push_back(i);
        }
        for(int i=2;i<=n;i++)
        {
            int p;
            cin >> p;
            vb[p].push_back(i);
        }
        dfsb(1);
        dfsa(1);
        cout << res << "\n";
        for(int i=1;i<=n;i++)
        {
            va[i].clear();
            vb[i].clear();
            tin[i]=tout[i]=0;
        }
        tcnt=1;
        res=0;
    }
    return 0;
}