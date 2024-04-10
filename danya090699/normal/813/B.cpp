#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, l, r, inf=2e18, an=0;
    cin>>x>>y>>l>>r;
    vector <int> stx(1), sty(1), ch(2);
    int cu=1;
    stx[0]=1, sty[0]=1;
    while(inf/x>cu)
    {
        cu*=x, stx.push_back(cu);
    }
    cu=1;
    while(inf/y>cu)
    {
        cu*=y, sty.push_back(cu);
    }
    ch[0]=l-1, ch[1]=r+1;
    for(int a=0; a<stx.size(); a++)
    {
        for(int b=0; b<sty.size(); b++)
        {
            int ne=stx[a]+sty[b];
            if(ne>=l and ne<=r) ch.push_back(ne);
        }
    }
    sort(ch.begin(), ch.end());
    for(int a=0; a<ch.size()-1; a++) an=max(an, ch[a+1]-ch[a]-1);
    cout<<an;
}