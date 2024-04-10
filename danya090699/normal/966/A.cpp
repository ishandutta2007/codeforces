#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, cl, ce, u;
    cin>>n>>m>>cl>>ce>>u;
    int l[cl], e[ce];
    for(int a=0; a<cl; a++) scanf("%d", &l[a]);
    for(int a=0; a<ce; a++) scanf("%d", &e[a]);
    sort(l, l+cl), sort(e, e+ce);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int x1, y1, x2, y2, an=1e9;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        if(y1==y2) an=abs(x1-x2);
        int p=lower_bound(l, l+cl, x1)-l;
        if(p<cl) an=min(an, abs(x1-l[p])+abs(x2-l[p])+abs(y1-y2));
        p--;
        if(p>=0) an=min(an, abs(x1-l[p])+abs(x2-l[p])+abs(y1-y2));
        p=lower_bound(e, e+ce, x1)-e;
        //cout<<abs(x2-e[p]);
        if(p<ce) an=min(an, abs(x1-e[p])+abs(x2-e[p])+de(abs(y1-y2), u));
        p--;
        if(p>=0) an=min(an, abs(x1-e[p])+abs(x2-e[p])+de(abs(y1-y2), u));
        printf("%d\n", an);
    }
}