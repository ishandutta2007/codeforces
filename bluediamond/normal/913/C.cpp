#include <bits/stdc++.h>
using namespace std;
struct data
{
    long long liter,pret;
};
bool cmp(data a,data b)
{
    return a.liter*b.pret>a.pret*b.liter;
}
const int nmax=30;
long long
 n,total,am,best=1e18,cost;
data v[nmax+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>total;
    v[1].liter=1;
    for(int i=2;i<=n;i++)
        v[i].liter=v[i-1].liter*2;
    for(int i=1;i<=n;i++)
        cin>>v[i].pret;
    sort(v+1,v+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int nev=total-am,iau=nev/v[i].liter;
        cost+=v[i].pret*iau;
        am+=iau*v[i].liter;
        if(nev%v[i].liter==0)
        {
            best=min(best,cost);
            cout<<best;
            return 0;
        }
        best=min(best,cost+v[i].pret);
    }
    return 0;
}
/**


**/