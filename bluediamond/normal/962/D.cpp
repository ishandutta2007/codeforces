#include <bits/stdc++.h>

using namespace std;

const int N=150000;

map<long long,set<int>>s;
long long n,v[N+5];

vector<long long>sl;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        s[v[i]].insert(i);
    }
    for(auto c:s)
    {
        while(c.second.size()>=2)
        {
            int x=*c.second.begin();
            int y=*next(c.second.begin());
            v[y]*=2;
            v[x]=-1;
            c.second.erase(x);
            c.second.erase(y);
            s[v[y]].insert(y);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=-1)
            sl.push_back(v[i]);
    }
    cout<<sl.size()<<"\n";
    for(int i=0;i<sl.size();i++)
        cout<<sl[i]<<" ";
    return 0;
}