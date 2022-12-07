#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, add;
    cin>>n>>m;
    for(int a=n; ; a++)
    {
        bool ok=1;
        for(int i=2; i*i<=a; i++)
        {
            if(a%i==0)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            add=a-n;
            break;
        }
    }
    cout<<2<<" "<<n+add<<"\n";
    for(int a=2; a<=n; a++)
    {
        int va=1;
        if(a==n) va=2;
        if(a==2) va+=add;
        cout<<1<<" "<<a<<" "<<va<<"\n";
        m--;
    }
    int u=2, v=3;
    while(m)
    {
        cout<<u<<" "<<v<<" "<<inf<<"\n";
        m--;
        v++;
        if(v>n)
        {
            u++, v=u+1;
        }
    }
}