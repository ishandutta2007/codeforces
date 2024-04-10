#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, d, x=1;
        cin>>n>>d;
        int cu=d;
        while(1)
        {
            int va=x+de(d, x+1);
            if(va>cu) break;
            cu=va, x++;
        }
        cout<<(cu<=n ? "YES\n" : "NO\n");
    }
}