#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e2+5)

string dp[2][MAXN];

char close(char c,int k)
{
    int v=c-'a';
    int v1=(v-1+k)%k;
    int v2=(v+1+k)%k;
    return min({v,v1,v2})+'a';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        dp[0][0]="";
        dp[1][0]="";
        string bb="";
        for(int i=0;i<n;i++)
        {
            bb.push_back('z');
            dp[0][i+1]=bb;
            dp[1][i+1]=bb;
        }

        for(int i=0;i<n;i++)
        {
//            db(i)
            string base=dp[1][i];
            base.push_back(close(s[i],k));
            dp[1][i+1]=min(dp[1][i+1],base);

            base.pop_back();
            if(i)
            {
                char c=base.back();
                base.pop_back();
                base.push_back(s[i]);
                base.push_back(c);
                dp[1][i+1]=min(dp[1][i+1],base);
                base.pop_back();
                base.pop_back();
                base.push_back(c);
            }
            if(i+1<n)
            {
                base.push_back(s[i+1]);
                base.push_back(s[i]);
                dp[0][i+2]=min(dp[0][i+2],base);
            }

            if(i)
            {
                base=dp[0][i+1];
                base[i-1]=close(base[i-1],k);
                dp[1][i+1]=min(dp[1][i+1],base);

                base=dp[0][i+1];
                if(i>1)
                {
                    swap(base[i-1],base[i-2]);
                    dp[1][i+1]=min(dp[1][i+1],base);
                }
            }
        }
        db(dp[1][n])
    }

    return 0;
}
/**
6
4 2
bbab
7 5
cceddda
6 5
ecdaed
7 4
dcdbdaa
8 3
ccabbaca
5 7
eabba

1
4 2
bbab
**/