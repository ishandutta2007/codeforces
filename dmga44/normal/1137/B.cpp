#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define mod (ll(2e9+99))
#define b (ll(331))
#define MAXN 500005

ll h[MAXN],p[MAXN];
char s[MAXN],t[MAXN];

ll hij(int i,int j)
{
    ll h1=h[j+1];
    ll h2=h[i];
    return (h1-((h2*p[j-i+1])%mod)+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    p[0]=1;
    for(int i=1;i<MAXN;i++)
        p[i]=(p[i-1]*b)%mod;

//    cin >> s >> t;
    scanf("%s %s",&s,&t);
    int ns=0;
    while(s[ns]=='0' || s[ns]=='1')
        ns++;
    int nt=0;
    while(t[nt]=='0' || t[nt]=='1')
        nt++;
//    int ns=s.size();
//    int nt=t.size();

    for(int i=0;i<nt;i++)
        h[i+1]=((h[i]*b)+t[i])%mod;

    int men=0;
    for(int i=1;i<nt;i++)
        if(hij(0,i-1)==hij(nt-i,nt-1))
            men=i;
    int fs[2],ft[2];
    fs[0]=fs[1]=ft[0]=ft[1]=0;
    for(int i=0;i<ns;i++)
        fs[s[i]-'0']++;
    int ms[2];
    ms[0]=ms[1]=0;
    for(int i=0;i<nt;i++)
        ft[t[i]-'0']++;
    for(int i=men;i<nt;i++)
        ms[t[i]-'0']++;
//    string res="";
    if(fs[0]>=ft[0] && fs[1]>=ft[1])
    {
        for(int j=0;j<nt;j++)
        {
//            string add=" ";
//            add[0]=t[j];
//            res=res+add;
            printf("%c",t[j]);
        }
        fs[0]-=ft[0];
        fs[1]-=ft[1];
        int mi=1000000;
        if(ms[0] && ms[1])
            mi=min(fs[0]/ms[0],fs[1]/ms[1]);
        else if(ms[0])
            mi=fs[0]/ms[0];
        else
            mi=fs[1]/ms[1];
        for(int i=0;i<mi;i++)
            for(int j=men;j<nt;j++)
            {
//                string add=" ";
//                add[0]=t[j];
//                res=res+add;
                printf("%c",t[j]);
            }
        fs[0]-=(ms[0]*mi);
        fs[1]-=(ms[1]*mi);
        while(fs[0])
        {
//            res=res+"0";
            fs[0]--;
            printf("0");
        }
        while(fs[1])
        {
//            res=res+"1";
            fs[1]--;
            printf("1");
        }
//        db(res)
//        printf("%s",res);
//        for(int i=0;i<res.size();i++)
//            printf("%c",res[i]);
    }
    else
//        db(s)
        printf("%s",s);

    return 0;
}