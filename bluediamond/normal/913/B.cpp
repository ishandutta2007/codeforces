#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int nmax=1000;
int n,a;
vector<int>v[nmax+5];
bool leaf[nmax+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>a;
        v[a].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(v[i].size()==0)
            leaf[i]=1;
    for(int i=1;i<=n;i++)
    {
        if(leaf[i]==1)
            continue;
        int s=0;
        for(int j=0;j<v[i].size();j++)
            if(leaf[v[i][j]])
                s++;
        if(s<3)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
/**

**/