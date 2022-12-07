#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, ok=1;
    cin>>m;
    int ar[m];
    for(int a=0; a<m; a++) cin>>ar[a];
    for(int a=1; a<m; a++) if(ar[a]%ar[0]) ok=0;
    if(ok)
    {
        cout<<m*2<<"\n";
        for(int a=0; a<m; a++) cout<<ar[0]<<" "<<ar[a]<<" ";
    }
    else cout<<-1;
}