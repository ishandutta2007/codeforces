#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        if(k==2)
        {
            int x2=1;
            for(int b=2; b*b<=x; b++)
            {
                if(x%b==0)
                {
                    int cu=0;
                    while(x%b==0) x/=b, cu^=1;
                    if(cu) x2*=b;
                }
            }
            if(x>1) x2*=x;
            q[x2]++;
        }
        else q[x]++;
    }
    if(k==2)
    {
        for(int a=0; a<sz; a++) if(q[a]) an+=(q[a]-1)*q[a]/2;
        cout<<an;
    }
    else
    {
        for(int a=1; ; a++)
        {
            int cu=1;
            for(int b=0; b<k; b++)
            {
                cu*=a;
                if(cu>sz*sz) break;
            }
            if(cu<sz*sz)
            {
                for(int b=1; b<sz; b++)
                {

                    if(cu%b==0)
                    {
                        int x=cu/b;
                        if(x<sz)
                        {
                            an+=q[b]*q[x];
                            if(b==x) an-=q[b];
                        }
                    }
                }
            }
            else break;
        }
        cout<<an/2;
    }
}