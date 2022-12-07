#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, h;
    cin>>n>>m>>h;
    int x[n], y[m];
    for(int a=0; a<m; a++) cin>>y[a];
    for(int a=0; a<n; a++) cin>>x[a];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int ok;
            cin>>ok;
            if(ok) cout<<min(x[a], y[b])<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}