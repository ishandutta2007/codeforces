//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=3e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

string d[MAXn][2];

ll p[MAXn];

ll fid(string a,string b)
{
    for (int i=1, j=p[0]=-1; i<SZ(b); i++)
    {
        
        while (j >= 0 && b[j+1] != b[i])
            j = p[j];
 
        if (b[j+1] == b[i]) j++;
 
        p[i] = j;
    }
    int j = -1;
    REP(i,SZ(a))
    {
        while(j >= 0 && b[j+1] != a[i])j = p[j];
        if(b[j+1] == a[i])j++;
        if(j == SZ(b)-1)
        {
            return i - SZ(b) + 1;
        }
    }
    return -1;
}

ll l[MAXn],r[MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(t,2)REP(i,n)cin>>d[i][t];
    ll len = -1;
    REP(i,n)
    {
        l[i] = -1;
        REP(j,SZ(d[i][0]))if(d[i][0][j] != d[i][1][j])
        {
            l[i] = j;
            break;
        }
        r[i] = -1;
        for(int j = SZ(d[i][0]) - 1;j >= 0;j --)if(d[i][0][j] != d[i][1][j])
        {
            r[i] = j;
            break;
        }
        if(l[i] != -1)
        {
            if(len != -1 && len != r[i] - l[i] + 1)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            len = r[i] - l[i] + 1;
        }
    }
    ll tl = 0;
    while(1)
    {
        bool ok = 1;
        ll c = -1;
        REP(i,n)
        {
            if(l[i] == -1)continue;
            if(l[i] - tl - 1 < 0 || (c != -1 && c != d[i][0][l[i] - tl - 1]))
            {
                ok = 0;
                break;
            }
            c = d[i][0][l[i] - tl - 1];
        }
        if(ok)tl ++;
        else break;
    }
    ll tr = 0;
    while(1)
    {
        bool ok = 1;
        ll c = -1;
        REP(i,n)
        {
            if(l[i] == -1)continue;
            if(r[i] + tr + 1 >= SZ(d[i][0]) || (c != -1 && c != d[i][0][r[i] + tr + 1]))
            {
                ok = 0;
                break;
            }
            c = d[i][0][r[i] + tr + 1];
        }
        if(ok)tr ++;
        else break;
    }
    debug(len,tl,tr);
    string s,t;
    REP(i,n)if(l[i] != -1)
    {
        s = d[i][0].substr(l[i] - tl,r[i] + tr - (l[i] - tl) + 1);
        t = d[i][1].substr(l[i] - tl,r[i] + tr - (l[i] - tl) + 1);
        break;
    }
    REP(i,n)
    {
        ll it = fid(d[i][0],s);
        if(it == -1)continue;
        REP(j,SZ(t))d[i][0][it + j] = t[j];
    }
    REP(i,n)if(d[i][0] != d[i][1])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<s<<endl;
    cout<<t<<endl;
}