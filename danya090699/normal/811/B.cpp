#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<m; a++)
    {
        int l, r, x, q=0;
        cin>>l>>r>>x;
        l--, r--, x--;
        for(int b=l; b<=r; b++) if(ar[b]<ar[x]) q++;
        if(l+q==x) cout<<"Yes\n";
        else cout<<"No\n";
    }
}