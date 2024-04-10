#include <bits/stdc++.h>
#define int long long
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int b, q, l, m, an=0;
    cin>>b>>q>>l>>m;
    set <int> se;
    for(int a=0; a<m; a++)
    {
        int x;
        cin>>x;
        se.insert(x);
    }
    for(int a=0; a<1000; a++)
    {
        if(mo(b)>l) break;
        else
        {
            if(se.find(b)==se.end()) an++;
            b*=q;
        }
    }
    if(an>100) cout<<"inf";
    else cout<<an;
}