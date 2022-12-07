#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int A, B, C, D;
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        int l=-1, r=de(C+1, D);
        while(r-l>1)
        {
            int mid=(l+r)>>1, q=min((mid+1)*D, C+1)-(mid+1);
            if(A-B*mid>q*B) l=mid;
            else r=mid;
        }
        if(r==de(C+1, D)) printf("-1\n");
        else
        {
            int an=0;
            for(int i=l; i<=r; i++)
            {
                if(i!=-1)
                {
                    int su=((i*(i+1)/2)*D-i)*B+i*B-(i+1)*A;
                    an=min(an, su);
                }
            }
            printf("%lld\n", -an);
        }
    }
}