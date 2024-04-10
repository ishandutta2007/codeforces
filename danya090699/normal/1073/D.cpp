#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=4e5+10;
int fen[2][sz];
void cha(int i, int p, int va)
{
    while(p<sz)
    {
        fen[i][p]+=va, p=p|(p+1);
    }
}
int que(int i, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[i][p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin>>n>>t;
    int ar[n], su=0, p=0, an=0;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]), su+=ar[a];
        cha(0, a, ar[a]), cha(0, a+n, ar[a]);
        cha(1, a, 1), cha(1, a+n, 1);
    }
    for(int q=n; q>0; q--)
    {
        //cout<<t<<" ";
        an+=(t/su)*q;

        t=t%su;
        int l=0, r=n;
        while(r-l>1)
        {
            int mid=(r+l)>>1;
            int ne=p+mid-1;
            int su=que(0, ne);
            if(p) su-=que(0, p-1);
            if(su<=t) l=mid;
            else r=mid;
        }
        //cout<<p<<" "<<l<<"\n";
        if(l>0)
        {
            int qq=que(1, p+l-1);
            if(p) qq-=que(1, p-1);
            int csu=que(0, p+l-1);
            if(p) csu-=que(0, p-1);
            an+=qq, t-=csu;
        }
        p=(p+l)%n;
        su-=ar[p];
        cha(0, p, -ar[p]), cha(0, p+n, -ar[p]);
        cha(1, p, -1), cha(1, p+n, -1);
        //cout<<an<<" ";
    }
    cout<<an;
}