#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, fo=0;
    cin>>n;
    int to[n];
    for(int a=0; a<n; a++)
    {
        cin>>to[a];
        to[a]--;
    }
    for(int a=0; a<n; a++) if(to[to[to[a]]]==a) fo=1;
    if(fo) cout<<"YES";
    else cout<<"NO";
}