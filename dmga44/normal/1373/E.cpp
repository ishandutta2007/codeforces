#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<string> s[30];
        for(int i=0;i<10;i++)
        {
            int sum=0;
            for(int j=0;j<=k;j++)
            {
                int d=(i+j)%10;
                sum+=d;
            }
            int p1=min((k+1),10-i);
            int p2=(k+1)-p1;

            int faltan=n-sum;
            if(faltan<0)
                continue;
//            db("")
//            cout << i << ' ' << faltan << '\n';
//            cout << p1 << ' ' << p2 << '\n';
            for(int c0=0;c0<20;c0++)
            {
                int s9s=c0*p1*9;
                int f2=faltan-s9s;
                if((f2-p2)<0 || (f2-p2)%(k+1))
                    continue;
                int x=(f2-p2)/(k+1);
//                cout << c0 << ' ' << x << '\n';
                vector<char> vs;
                while(x>=9)
                {
                    vs.push_back('9');
                    x-=9;
                }
                if(x)
                    vs.push_back(x+'0');

                if(p2 && vs.size() && vs[0]=='9')
                {
                    if(vs.size()>1)
                    {
                        vs[0]='8';
                        if(vs.back()=='9')
                            vs.push_back('1');
                        else
                            vs[vs.size()-1]=vs[vs.size()-1]+1;
                    }
                    else
                    {
                        vs[0]='8';
                        vs.push_back('1');
                    }
                }
                reverse(all(vs));
                for(int cc=0;cc<c0;cc++)
                    vs.push_back('9');
                vs.push_back('0'+i);
                reverse(all(vs));
                string ss;
                for(int ii=0;ii<vs.size();ii++)
                    ss=ss+vs[ii];
                reverse(all(ss));
                s[ss.size()].push_back(ss);
//                db(ss)
//                db("")
            }
        }

        string res="-1";
        for(int i=1;i<30;i++)
        {
            if(!s[i].size())
                continue;
            sort(all(s[i]));
            res=s[i][0];
            break;
        }
        db(res)
    }

    return 0;
}
/**
7
1 0
1 1
42 7
13 7
99 1
99 0
99 2

1
99 1
**/