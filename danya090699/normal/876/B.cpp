#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, fo=0;
    cin>>n>>k>>m;
    vector <int> ve[m];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ve[x%m].push_back(x);
    }
    for(int a=0; a<m; a++)
    {
        if(ve[a].size()>=k)
        {
            cout<<"Yes\n";
            for(int b=0; b<k; b++) cout<<ve[a][b]<<" ";
            fo=1;
            break;
        }
    }
    if(fo==0) cout<<"No";
}