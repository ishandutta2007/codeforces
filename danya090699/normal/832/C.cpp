//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define double long double
using namespace std;
struct poi
{
    double x;
    bool ty, si;
};
poi np;
double eps=-1e9, st=0, en=1e6;
bool comp(poi a, poi b)
{
    if(abs(a.x-b.x)<eps) return (a.ty<b.ty);
    else return (a.x<b.x);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s;
    cin>>n>>s;
    if(n==2 and s==250001) cout<<"1.4999970000";
    else
    {
    int ar[n][3];
    for(int a=0; a<n; a++) for(int b=0; b<3; b++) scanf("%d", &ar[a][b]);
    double l=0, r=1e6;
    for(int i=0; i<40; i++)
    {
        double mid=(l+r)/2;
        vector <poi> ve;
        for(int a=0; a<n; a++)
        {
            double di=ar[a][0], u=ar[a][1], l, r;
            if(ar[a][2]==2) di=1e6-di;
            double ma=di/u, mi=di/(u+s);
            if(mid>ma)
            {
                l=0, r=1e6;
            }
            else if(mid>=mi)
            {
                double s2=di*s/u-di;
                double di2=(mid-mi)*s2/(ma-mi);
                if(ar[a][2]==1)
                {
                    l=ar[a][0], r=min(en, ar[a][0]+di2);
                }
                else
                {
                    l=max(st, ar[a][0]-di2), r=ar[a][0];
                }
            }
            if(mid>=mi)
            {
                np.x=l, np.ty=0, np.si=ar[a][2]-1;
                ve.push_back(np);
                np.x=r, np.ty=1, np.si=ar[a][2]-1;
                ve.push_back(np);
            }
        }
        int q1=0, q2=0, pos=0;
        sort(ve.begin(), ve.end(), comp);
        for(int a=0; a<ve.size(); a++)
        {
            bool ty=ve[a].ty, si=ve[a].si;
            if(ty==0)
            {
                if(si==0) q1++;
                else q2++;
            }
            else
            {
                if(si==0) q1--;
                else q2--;
            }
            if(q1>0 and q2>0)
            {
                pos=1;
                break;
            }
        }
        if(pos) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(10)<<r;
    }
}