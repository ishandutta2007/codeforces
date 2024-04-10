#include <bits/stdc++.h>

using namespace std;

const int N=1000000+5;

int n;
bool seen[N];

inline int inv(int x)
{
    return 1000001-x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        seen[x]=1;
    }
    vector<pair<int,int>>space;
    for(int i=1;i<inv(i);i++)
    {
        if(seen[i]==0 && seen[inv(i)]==0)
        {
            space.push_back({i,inv(i)});
        }
    }
    vector<int>ans;
    for(int i=1;i<inv(i);i++)
    {
        if(seen[i]==1 && seen[inv(i)]==0)
        {
            ans.push_back(inv(i));
        }
        if(seen[i]==0 && seen[inv(i)]==1)
        {
            ans.push_back(i);
        }
        if(seen[i]==1 && seen[inv(i)]==1)
        {
            ans.push_back(space.back().first);
            ans.push_back(space.back().second);
            space.pop_back();
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}