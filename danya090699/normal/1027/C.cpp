#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n);
        vector <int> ve;
        int yk=0;
        while(yk<n)
        {
            int cu=ar[yk], q=0;
            while(yk<n)
            {
                if(ar[yk]==cu)
                {
                    yk++, q++;
                }
                else break;
            }
            if(q>=2) ve.push_back(cu);
            if(q>=4) ve.push_back(cu);
        }
        int bx=1, by=0;
        for(int a=0; a+1<ve.size(); a++)
        {
            int x=ve[a], y=ve[a+1];
            int bch=bx*bx+by*by, bzn=bx*by, ch=x*x+y*y, zn=x*y;
            if((1ll*bch*zn)>(1ll*ch*bzn))
            {
                bx=x, by=y;
            }
        }
        printf("%d %d %d %d\n", bx, bx, by, by);
    }
}