#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, in=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++) if(ar[b]<ar[a]) in^=1;
    }
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int l, r;
        cin>>l>>r;
        in^=(((r-l+1)*(r-l))/2)%2;
        if(in) cout<<"odd\n";
        else cout<<"even\n";
    }
}