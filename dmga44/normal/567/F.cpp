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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)
#define MAXN 75

ll dp[MAXN][MAXN];
string s[MAXN*2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    vector<pii> res;
    for(int i=0;i<k;i++)
    {
        int p1,p2;
        cin >> p1 >> s[i] >> p2;
        p1--,p2--;
        if(p1>p2)
        {
            swap(p1,p2);
            if(s[i]==">")
                s[i]="<";
            else if(s[i]=="<")
                s[i]=">";
            if(s[i]==">=")
                s[i]="<=";
            else if(s[i]=="<=")
                s[i]=">=";
        }
        res.push_back(pii(p1,p2));
    }

    for(int i=0;i+1<(2*n);i++)
    {
        int p1=i;
        int p2=i+1;
        bool ok=1;
//        db("")
//        db(i)
        for(int j=0;j<k;j++)
            if(res[j].first==p1 || res[j].s==p1 || res[j].s==p2 || res[j].first==p2)
            {
                int c1=res[j].f;
                int c2=res[j].s;
//                cout << c1 << s[j] << c2 << '\n';
                int cont=0;
                if(c1==p1 || c1==p2)
                    cont++;
                if(c2==p1 || c2==p2)
                    cont++;
                if(cont==2)
                {
                    if(s[j]==">" || s[j]=="<")
                        ok=0;
                    continue;
                }
                if(c1==p1 || c1==p2)
                {
                    if(s[j]!=">" && s[j]!=">=")
                        ok=0;
                    continue;
                }
                if(s[j]!="<" && s[j]!="<=")
                    ok=0;
            }
        dp[i][i+1]=ok;
    }

    for(int i=1;i<=2*n-1;i+=2)
    {
        for(int p=0;p+i<2*n;p++)
        {
            if(p>=2)
            {
                int p1=p-2;
                int p2=p-1;
                bool ok=1;
                for(int j=0;j<k;j++)
                    if(res[j].f==p1 || res[j].s==p1 || res[j].s==p2 || res[j].f==p2)
                    {
                        int c1=res[j].f;
                        int c2=res[j].s;
                        int cont=0;
                        if(c1==p1 || c1==p2)
                            cont++;
                        if(c2==p1 || c2==p2)
                            cont++;
                        if(cont==2)
                        {
                            if(s[j]==">" || s[j]=="<")
                                ok=0;
                            continue;
                        }
                        if(c1<p1 || c2>p+i)
                        {
                            if(c1==p1 || c1==p2)
                            {
                                if(s[j]!=">" && s[j]!=">=")
                                    ok=0;
                                continue;
                            }
                            if(s[j]!="<" && s[j]!="<=")
                                ok=0;
                        }
                        else
                        {
                            if(c1==p1 || c1==p2)
                            {
                                if(s[j]!="<" && s[j]!="<=")
                                    ok=0;
                                continue;
                            }
                            if(s[j]!=">" && s[j]!=">=")
                                ok=0;
                        }
                    }
                if(ok)
                    dp[p1][p+i]+=dp[p][p+i];
            }
            if(p+i+2<2*n)
            {
                int p1=p+i+1;
                int p2=p+i+2;
                bool ok=1;
                for(int j=0;j<k;j++)
                    if(res[j].first==p1 || res[j].s==p1 || res[j].s==p2 || res[j].first==p2)
                    {
                        int c1=res[j].f;
                        int c2=res[j].s;
                        int cont=0;
                        if(c1==p1 || c1==p2)
                            cont++;
                        if(c2==p1 || c2==p2)
                            cont++;
                        if(cont==2)
                        {
                            if(s[j]==">" || s[j]=="<")
                                ok=0;
                            continue;
                        }
                        if(c1<p || c2>p2)
                        {
                            if(c1==p1 || c1==p2)
                            {
                                if(s[j]!=">" && s[j]!=">=")
                                    ok=0;
                                continue;
                            }
                            if(s[j]!="<" && s[j]!="<=")
                                ok=0;
                        }
                        else
                        {
                            if(c1==p1 || c1==p2)
                            {
                                if(s[j]!="<" && s[j]!="<=")
                                    ok=0;
                                continue;
                            }
                            if(s[j]!=">" && s[j]!=">=")
                                ok=0;
                        }
                    }
                if(ok)
                    dp[p][p2]+=dp[p][p+i];
            }
            if(p && p+i+1<2*n)
            {
                int p1=p-1;
                int p2=p+i+1;
                bool ok=1;
                for(int j=0;j<k;j++)
                    if(res[j].first==p1 || res[j].s==p1 || res[j].s==p2 || res[j].first==p2)
                    {
                        int c1=res[j].f;
                        int c2=res[j].s;
                        int cont=0;
                        if(c1==p1 || c1==p2)
                            cont++;
                        if(c2==p1 || c2==p2)
                            cont++;
                        if(cont==2)
                        {
                            if(s[j]==">" || s[j]=="<")
                                ok=0;
                            continue;
                        }
                        if(c1<p1 || c2>p2)
                        {
                            if(c1==p1 || c1==p2)
                            {
                                if(s[j]!=">" && s[j]!=">=")
                                    ok=0;
                                continue;
                            }
                            if(s[j]!="<" && s[j]!="<=")
                                ok=0;
                        }
                        else
                        {
                            if(c1==p1 || c1==p2)
                            {
                                if(s[j]!="<" && s[j]!="<=")
                                    ok=0;
                                continue;
                            }
                            if(s[j]!=">" && s[j]!=">=")
                                ok=0;
                        }
                    }
                if(ok)
                    dp[p1][p2]+=dp[p][p+i];
            }
        }
    }

//    for(int i=0;i<2*n;cout << '\n',i++)
//        for(int j=0;j<2*n;j++)
//            cout << dp[i][j] << ' ';
    db(dp[0][2*n-1])

    return 0;
}
/**
5 8
8 = 9
7 >= 7
3 <= 9
4 > 10
5 >= 1
7 = 7
2 < 6
4 <= 7
**/