#include<bits/stdc++.h>

using namespace std;

const int N=100;

int n;

struct info
{
    int nod,c,inv;
};

vector<info>v[N+5];
bool viz[N+5];

int c1,c2;

void dfs(int nod)
{
    viz[nod]=1;
    for(auto aux:v[nod])
    {
        int nou=aux.nod;
        int c=aux.c;
        int inv=aux.inv;
        if(viz[nou]==1)
            continue;
        if(inv==1)
            c1+=c;
        else
            c2+=c;
        dfs(nou);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c,0});
        v[b].push_back({a,c,1});
    }
    dfs(1);
    info aux=v[1][1];
    int c=aux.c;
    int inv=aux.inv;
    if(inv==0)
        c1+=c;
    else
        c2+=c;
    cout<<min(c1,c2)<<"\n";
    return 0;
}