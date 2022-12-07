#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
bool fi[2][sz];
bool f(int i)
{
    return ((fi[0][i]&fi[0][i+1])|(fi[1][i]&fi[1][i+1]));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, su;
    cin>>n>>q;
    su=n-1;
    for(int a=0; a<2; a++) for(int b=0; b<n; b++) fi[a][b]=1;
    for(int a=0; a<q; a++)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        r--, c--;
        if(c) su-=f(c-1);
        if(c+1<n) su-=f(c);
        fi[r][c]^=1;
        if(c) su+=f(c-1);
        if(c+1<n) su+=f(c);

        if(su==n-1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}