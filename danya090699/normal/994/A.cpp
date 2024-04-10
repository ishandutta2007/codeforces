#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n];
    set <int> se;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<m; a++)
    {
        int x;
        cin>>x;
        se.insert(x);
    }
    for(int a=0; a<n; a++)
    {
        if(se.find(ar[a])!=se.end()) cout<<ar[a]<<" ";
    }
}