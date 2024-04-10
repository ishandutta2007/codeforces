#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=998244353;
int q[sz], st[sz], an[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
int SUM(int x, int y)
{
    return (x+y<mod) ? x+y : x+y-mod;
}
int DIF(int x, int y)
{
    return (x-y>=0) ? x-y : x-y+mod;
}
int MUL(int x, int y)
{
    return 1ll*x*y%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int p;
        scanf("%d", &p);
        scanf("%d", &q[p]);
    }
    for(int a=1; a<sz; a++)
    {
        st[a]=po(2, q[a]);
    }

    int rev=po(2, mod-2);

    for(int a=sz-1; a; a--)
    {
        long long cnt2=0;
        int cnt=0, su=0, st2=1;

        for(int b=a; b<sz; b+=a)
        {
            cnt2+=q[b];
            cnt=SUM(cnt, q[b]%mod);
            su=SUM(su, MUL(q[b], b));
            st2=MUL(st2, st[b]);
        }

        st2=MUL(st2, rev);
        st2=MUL(st2, rev);

        for(int b=a; b<sz; b+=a)
        {
            if(cnt2>1 and q[b])
            {
                int add=MUL(b, MUL(DIF(cnt, 1), st2));

                add=SUM(add, MUL(DIF(su, b), st2));

                if(cnt2>2)
                {
                    st2=MUL(st2, rev);

                    add=SUM(add, MUL(st2, MUL(DIF(su, b), DIF(cnt, 2))));

                    st2=MUL(st2, 2);
                }

                add=MUL(add, b);
                add=MUL(add, q[b]);

                an[a]=SUM(an[a], add);
            }
        }

        for(int b=a+a; b<sz; b+=a) an[a]=DIF(an[a], an[b]);
    }
    cout<<an[1];
}