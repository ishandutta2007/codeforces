#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int fen[sz];
void cha(int p)
{
    while(p<sz)
    {
        fen[p]++, p=p|(p+1);
    }
}
int que(int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}
bool comp(pair <int, int> a, pair <int, int> b)
{
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar2[n];
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a].first);
        ar2[a]=ar[a].first;
        ar[a].second=a;
    }
    sort(ar, ar+n, comp);
    int m;
    cin>>m;
    int an[m];
    pair <pair <int, int>, int> qu[m];
    for(int a=0; a<m; a++)
    {
        scanf("%d%d", &qu[a].first.first, &qu[a].first.second);
        qu[a].second=a;
    }
    sort(qu, qu+m);
    int yk=0;
    for(int a=0; a<m; a++)
    {
        while(yk<qu[a].first.first)
        {
            cha(ar[yk].second), yk++;
        }
        int l=-1, r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(que(mid)<qu[a].first.second) l=mid;
            else r=mid;
        }
        an[qu[a].second]=ar2[r];
    }
    for(int a=0; a<m; a++) printf("%d\n", an[a]);
}