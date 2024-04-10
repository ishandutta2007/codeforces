#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(0));

inline pair<int,int>ask(int id)
{
    cout<<"? "<<id<<endl;
    int a,b;
    cin>>a>>b;
    return {a,b};
}

inline void print(int ans)
{
    cout<<"! "<<ans<<endl;
    exit(0);
}

int main()
{
    int n,start,x;
    cin>>n>>start>>x;
    vector<pair<int,int>>e;
    e.push_back(ask(start));
    for(int i=1;i<1000;i++)
    {
        e.push_back(ask(rnd()%n+1));
    }
    sort(e.begin(),e.end());
    if(e[0].first>=x)
    {
        print(e[0].first);
    }
    int id=-1;
    for(auto &it:e)
    {
        if(it.first<x)
        {
            id=it.second;
        }
    }
    while(id!=-1)
    {
        pair<int,int>aux=ask(id);
        if(aux.first>=x)
        {
            print(aux.first);
        }
        else
        {
            id=aux.second;
        }
    }
    print(id);
    return 0;
}