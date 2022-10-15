#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

typedef long long ll;
///#define int long long

const int M=(int) 1e9+7;

int add(int a, int b)
{
        a+=b;
        if (a>=M) return a-M;
        if (a<0) return a+M;
        return a;
}

int mul(int a, int b)
{
        return a*(ll)b%M;
}

void addup(int &a, int b)
{
        a=add(a, b);
}

int pw(int a, int b)
{
        int r=1;
        while (b)
        {
                if (b&1)
                        r=mul(r, a);
                a=mul(a, a);
                b/=2;
        }
        return r;
}

int dv(int a, int b)
{
        return mul(a, pw(b, M-2));
}

const int N=(int) 2e5+7;
int n, l, r, fact[N], ifact[N];

int comb(int n, int k)
{
        assert(0<=k && k<=n);
        return mul(fact[n], mul(ifact[k], ifact[n-k]));
}


int compute(int c1, int c2, int both, int t1, int t2)
{
        if (c1>t1) return 0;
        if (c2>t2) return 0;

        t1-=c1;
        t2-=c2;
        return comb(both, t1);
}

vector<int> eval(int x)
{
        int c1=0, c2=0, both=0;

        both=max(0, min(r-x, n)-max(l+x,1)+1);
        c1=max(0, min(r-x, n)-max(l-x,1)+1);
        c2=max(0, min(r+x, n)-max(l+x,1)+1);
        c1-=both;
        c2-=both;

        return {c1, c2, both};
}

int smart()
{
        int sol=0;
        for (int x=1; x<=r; x++)
        {
                auto it=eval(x);
                int c1=it[0], c2=it[1], both=it[2];

                if (c1+c2+both<n)
                        break;

                if (eval(x)==eval(x+1))
                {
                        int lo=x, hi=r, kek=-1;
                        while (lo<=hi)
                        {
                                int mid=(lo+hi)/2;
                                if (eval(x)==eval(mid))
                                {
                                        kek=mid;
                                        lo=mid+1;
                                }
                                else
                                        hi=mid-1;
                        }
                        assert(kek!=-1);

                        int now=0;
                        addup(now, compute(c1, c2, both, n/2, (n+1)/2));
                        if (n&1)
                                addup(now, compute(c1, c2, both, (n+1)/2, n/2));

                        addup(sol, mul(kek-x+1, now));
                        x=kek;
                        continue;
                }



                addup(sol, compute(c1, c2, both, n/2, (n+1)/2));
                if (n&1)
                {
                       /// cout<<compute(c1, c2, both, n/2, (n+1)/2)<<" and "<<compute(c1, c2, both, (n+1)/2, n/2)<<"\n";
                        addup(sol, compute(c1, c2, both, (n+1)/2, n/2));
                }
        }
        return sol;
}



signed main()
{
    ///    freopen ("input", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0); /// Just for aesthetics this time

        fact[0]=1;
        for (int i=1; i<N;i++)
                fact[i]=mul(fact[i-1], i);
        ifact[N-1]=dv(1, fact[N-1]);
        for (int i=N-2; i>=0; i--)
                ifact[i]=mul(ifact[i+1], i+1);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n>>l>>r;
                cout<<smart()<<"\n";
        }
        return 0;
}


/**

**/