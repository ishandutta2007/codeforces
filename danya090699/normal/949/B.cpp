#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<q; a++)
    {
        int x;
        scanf("%lld", &x);
        x--;
        int yk=0, st=0, l=1, ch=0;
        while(yk<n)
        {
            int q=n-yk;
            if(((x-st)/l)%2==ch)
            {
                int fi=st+l*ch;
                printf("%lld\n", yk+(x-fi)/(l*2)+1);
                break;
            }
            if(ch==0) st+=l;
            if(q&1)
            {
                yk+=de(q, 2)-ch;
                ch^=1;
            }
            else yk+=q/2;
            l*=2;
        }
    }
}