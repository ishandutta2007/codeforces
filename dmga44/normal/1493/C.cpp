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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int n,k;

bool ok(vector<int>& f,int l)
{
    int sum=0;
    for(int i=0;i<26;i++)
        if(f[i])
            sum+=(k-f[i]);
    return sum<=l;
}

string solve(string x)
{
    int fal=n-x.size();
    vector<int> f(26);
    for(auto c : x)
        f[c-'a']=(f[c-'a']+1)%k;
    int sum=0;
    for(int i=0;i<26;i++)
        if(f[i])
            sum+=(k-f[i]);
    for(int i=0;i<fal-sum;i++)
        x.push_back('a');
    for(int i=0;i<26;i++)
        if(f[i])
            for(int j=0;j<k-f[i];j++)
                x.push_back('a'+i);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        string s;
        cin >> s;
        if(n%k)
        {
            db(-1)
            continue;
        }
        string res=s;

        vector<int> f(26);
        for(int i=0;i<n;i++)
            f[s[i]-'a']=(f[s[i]-'a']+1)%k;
        for(int i=0;i<=n;i++)
        {
            if(ok(f,i))
            {
//                db(i)
                if(!i)
                    break;
                else
                {
                    bool kk=0;
                    for(int j=s[n-i]+1;j<='z';j++)
                    {
                        res.push_back(j);
//                        db(res)
                        f[j-'a']=(f[j-'a']+1)%k;
                        if(ok(f,i-1))
                        {
//                            db(res)
                            res=solve(res);
                            kk=1;
                            break;
                        }
                        else
                        {
                            res.pop_back();
                            f[j-'a']=(f[j-'a']+k-1)%k;
                        }
                    }

                    if(!kk)
                    {
                        f[s[n-i-1]-'a']=(f[s[n-i-1]-'a']+k-1)%k;
                        res.pop_back();
                    }
                    if(kk)
                        break;
                }
            }
            else
            {
                f[s[n-i-1]-'a']=(f[s[n-i-1]-'a']+k-1)%k;
                res.pop_back();
            }
        }
        db(res)
    }

    return 0;
}