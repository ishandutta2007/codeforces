#include <bits/stdc++.h>

using namespace std;

const int N=1000+5;

struct info
{
    int nod;
    int cnt;
};

vector<int>g[N];
int adj[N][N];

vector<info>have;

int nxt=3;

inline void add(int a,int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
    adj[a][b]=adj[b][a]=1;
}

inline void expand()
{
    info nou;
    nou.nod=nxt++;
    nou.cnt=0;
    for(auto itr:have)
        nou.cnt+=itr.cnt, add(nou.nod,itr.nod);
    for(int i=0;i<have.size();i++)
        add(nxt,have[i].nod), have[i].nod=nxt++;
    have.push_back(nou);
}

void print()
{
    int n=0;
    for(int i=1;i<N;i++)
        if(g[i].size())
            n=i;
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(adj[i][j])
                cout<<"Y";
            else
                cout<<"N";
        cout<<"\n";
    }
    return;
    for(int i=1;i<=n;i++)
        for(auto j:g[i])
            cout<<i<<" "<<j<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    have.push_back({1,1});
    int need;
    cin>>need;
    if(need==1)
    {
        add(1,2);
        print();
        return 0;
    }
    int lg=log2(need);
    for(int j=1;j<=lg+1;j++)
        expand();
    bool f=1;
    for(auto itr:have)
    {
        if(need&itr.cnt && !f)
            add(2,itr.nod);
        f=0;
    }
    print();
    return 0;
}
/**

**/