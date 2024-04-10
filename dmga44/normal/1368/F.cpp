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
#define MAXN (ll)(1e3+5)

void finish()
{
    cout << 0 << '\n';
    cout.flush();
    exit(0);
}

bool mk[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    if(n<=3)
        finish();

    pii tar=pii(n,-1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            mk[j]=1;
        for(int j=0;j<n;j+=i)
            mk[j]=1;
        int cant=0;
        for(int j=0;j<n;j++)
        {
            cant+=mk[j];
            mk[j]=0;
        }
        tar=min(pii(cant,i),tar);
    }

    int x=tar.s;
    vector<int> pos;
    for(int i=1;i<x;i++)
        for(int j=i;j<n;j+=x)
            pos.push_back(j);
    while(1)
    {
        int fal=0;
        for(int i=0;i<n;i++)
            fal+=!mk[i];

        if(fal==tar.first)
            break;

        vector<int> ps;
        for(int i=0;i<pos.size();i++)
            if(ps.size()<x && !mk[pos[i]])
            {
                ps.push_back(pos[i]);
                mk[pos[i]]=1;
            }
        cout << ps.size();
        for(auto y : ps)
            cout << ' ' << y+1;
        cout << '\n';
        cout.flush();
        int p;
        cin >> p;
        p--;
        for(int i=0;i<ps.size();i++)
            mk[(p+i)%n]=0;
    }
    finish();

    return 0;
}