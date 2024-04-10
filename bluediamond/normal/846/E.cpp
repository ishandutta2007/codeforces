#include <bits/stdc++.h>


typedef long long ll;
typedef long double ld;


using namespace std;

const int N=100000+5;

int n;
ld am[N];
ld nev[N];
ld k[N];

vector<int>g[N];

inline void dfs(int nod,int dad)
{
    for(auto nou:g[nod])
    {
        dfs(nou,nod);
    }
  ///  cout<<"ROFL : "<<nod<<" : "<<am[nod]<<" , "<<nev[nod]<<"\n";
    if(am[nod]>=nev[nod]) /// donate to dad
    {
        am[dad]+=(am[nod]-nev[nod]);
        am[nod]=nev[nod];
    }
    else
    {
        if(nod==1)
        {
            cout<<"NO\n";
            exit(0);
        }
        ld need=(nev[nod]-am[nod])*k[nod];
   ///     cout<<"\t\tLOLOLOL "<<nod<<" - > "<<need<<"\n";
        am[dad]-=need;
        am[nod]=nev[nod];
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>am[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>nev[i];
    }
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x>>k[i];
        g[x].push_back(i);
    }
    dfs(1,-1);
    if(am[1]>=nev[1])
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}