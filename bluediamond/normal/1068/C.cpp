#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;
int n,m;
int x[N+5],y[N+5];

vector<pair<int,int>>who[105];

inline void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<who[i].size()<<"\n";
        for(auto itr:who[i])
        {
            cout<<itr.first<<" "<<itr.second<<"\n";
        }
  ///      cout<<"\n";
    }
}

inline void add(int i,int poz)
{
    who[i].push_back({i,poz});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
    }
    int poz=1;
    for(int i=1;i<=n;i++)
    {
        add(i,poz);
        poz++;
    }
    for(int i=1;i<=m;i++)
    {
        int a=x[i];
        int b=y[i];
        add(a,poz);
        add(b,poz);
        poz++;
    }
    print();
    return 0;
}