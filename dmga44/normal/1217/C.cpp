#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        vector<int> last(n+1);
        last[n]=MAXN;
        for(int i=n-1;i>=0;i--)
        {
            last[i]=last[i+1];
            if(s[i]=='1')
                last[i]=i;
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            int pos=last[i];
            int sz=pos-i+1;
            int sum=1;
            if(sum==sz)
                res++;
            while(pos<n-1 && sum<=sz)
            {
                sz++;
                pos++;
                sum*=2;
                sum+=s[pos]-'0';
                if(sz==sum)
                    res++;
            }
        }
        db(res)
    }

    return 0;
}
/**
4
0110
0101
00001000
0001000
**/