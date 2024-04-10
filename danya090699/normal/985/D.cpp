#include <bits/stdc++.h>
#define int long long
using namespace std;
bool comp(int x, int y, int z){return (z/x<y);}//x*y>z
bool comp2(int x, int y, int z)//x*y>=z
{
    return ((z/x<y) or (z/x==y and z%x==0));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n2, h;
    cin>>n2>>h;
    int l=0, r=n2;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int x=mid-h+1;
        int n=n2;
        if(x<=0)
        {
            if(comp2(mid+1, mid, n*2)) r=mid;
            else l=mid;
        }
        else
        {
            if(comp(x+mid, h, n*2)) r=mid;
            else
            {

                n-=((x+mid)*h)/2;
                if(x<3)
                {
                    if(n==0) r=mid;
                    else l=mid;
                }
                else
                {
                    int lq=(x-1)/2, fi=x-2, la=1;
                    if(x%2==0) la++;
                    //if(mid==5) cout<<fi<<" "<<la<<" "<<lq<<" "<<n;
                    if(comp2(fi+la, lq, n*2)) r=mid;
                    else l=mid;
                }
            }
        }
    }
    cout<<r;
}