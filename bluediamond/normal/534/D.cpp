#include <bits/stdc++.h>

using namespace std;

const int N=200000+5;

int n;
vector<int>v[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    int x=0;
    for(int i=1;i<=n;i++)
    {
        while(x>=0 && v[x].empty())
            x-=3;
        if(x<0)
        {
            cout<<"Impossible\n";
            return 0;
        }
        ans.push_back(v[x].back());
        v[x].pop_back();
        x++;
    }
    cout<<"Possible\n";
    for(auto x:ans)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}
/**

**/