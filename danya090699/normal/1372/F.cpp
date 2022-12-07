#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int ar[sz];
void dfs(int l, int r, int x, int f)
{
    int len=r-l+1;

    if(f==len)
    {
        for(int a=l; a<=r; a++) ar[a]=x;
    }
    else
    {
        int x2, f2;

        cout<<"? "<<l+f<<" "<<r<<"\n";
        cin>>x2>>f2;

        if(f2==len-f and x2==x)
        {
            dfs(r-f+1, r, x, f);
            r=r-f;
        }
        else
        {
            dfs(l+f, r, x2, f2);
            r=l+f-1;
        }

        cout<<"? "<<l<<" "<<r<<"\n";
        cin>>x2>>f2;

        dfs(l, r, x2, f2);
    }
}
main()
{
    int n;
    cin>>n;
    cout<<"? "<<1<<" "<<n<<"\n";
    int x, f;
    cin>>x>>f;
    dfs(1, n, x, f);
    cout<<"!";
    for(int a=1; a<=n; a++) cout<<" "<<ar[a];
    cout<<"\n";
}