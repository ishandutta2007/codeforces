#include <bits/stdc++.h>
#define int long long
using namespace std;
int po(int x, int y, int mod)
{
    int re=1;
    while(y)
    {
        if(y&1) re=re*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return re;
}
const int sz=2e5+10;
int fen[sz];
void cha(int p, int va)
{
    while(p<sz)
    {
        fen[p]+=va, p=p|(p+1);
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
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q[m], q2[m], ar[n];
    for(int a=0; a<m; a++) q[a]=0, q2[a]=0;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int va=x%m;
        for(int b=0; b<m; b++)
        {
            int y=b-va;
            if(y<0) y+=m;
            q2[y]+=q[b];
        }
        q[va]++;
        ar[a]=x;
        ma[x]=0;
    }
    int n2=0, mi=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=n2++;
    for(int a=0; a<n; a++)
    {
        int x=ma[ar[a]];
        mi+=que(x-1);
        cha(x, 1);
    }
    int an=1;
    for(int a=0; a<m; a++) an=an*po(a, q2[a], m)%m;
    if(mi&1) an=(m-an)%m;
    cout<<an;
}