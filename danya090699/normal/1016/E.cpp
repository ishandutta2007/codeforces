#include <bits/stdc++.h>
using namespace std;
double f(int x, int y, int x2, int sy)
{
    int vx=x2-x;
    double k=(y+sy)/(y*1.0);
    return x+vx*k;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int sy, L, R, n;
    cin>>sy>>L>>R>>n;
    sy=-sy;
    int ot[n][2], pref[n+1];
    pref[0]=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &ot[a][0], &ot[a][1]);
        pref[a+1]=pref[a]+(ot[a][1]-ot[a][0]);
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int lo, ro;
        double an=0;
        int ll=-1, rr=n;
        while(rr-ll>1)
        {
            int mid=(ll+rr)>>1;
            double p=f(x, y, ot[mid][0], sy);
            if(p>=L) rr=mid;
            else ll=mid;
        }
        lo=ll;
        if(lo!=-1)
        {
            double pl=f(x, y, ot[lo][0], sy);
            double pr=f(x, y, ot[lo][1], sy);
            double LL=L, RR=R;
            pl=max(pl, LL), pr=min(pr, RR);
            if(pl<pr) an+=pr-pl;
        }
        ll=-1, rr=n;
        while(rr-ll>1)
        {
            int mid=(ll+rr)>>1;
            double p=f(x, y, ot[mid][1], sy);
            if(p<=R) ll=mid;
            else rr=mid;
        }
        ro=rr;
        if(ro!=n and ro>lo)
        {
            double pl=f(x, y, ot[ro][0], sy);
            double pr=f(x, y, ot[ro][1], sy);
            double LL=L, RR=R;
            pl=max(pl, LL), pr=min(pr, RR);
            if(pl<pr) an+=pr-pl;
        }
        if(ro>lo) an+=(y+sy)/(y*1.0)*(pref[ro]-pref[lo+1]);
        cout<<fixed<<setprecision(10)<<an<<"\n";
    }
}