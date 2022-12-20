//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=1e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(2e18);


ll n,t;
string s1,s2;
string s;
char dif(char a, char b)
{
    if(a!='a'&&b!='a')return 'a';
    else if(a!='b'&&b!='b')return 'b';
    else return 'c';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>t;
    cin>>s1>>s2;
    s=s1;
    ll k=0;
    REP(i,n)k+=(s1[i]!=s2[i]);
    if(k/2+(k%2)>t){cout<<-1<<endl;return 0;}
    ll a,b,c,d;
    if(t<k)
    {
        a=k-t;
        b=a;
        c=k-2*a;
        d=0;
    }
    else
    {
        a=0;
        b=0;
        c=k;
        d=t-k;
    }
    REP(i,n)
    {
        if(s1[i]!=s2[i])
        {
            if(a)s[i]=s1[i],a--;
            else if(b)s[i]=s2[i],b--;
            else if(c)s[i]=dif(s1[i],s2[i]),c--;
        }
        else if(d)s[i]=dif(s1[i],s2[i]),d--;
    }
    cout<<s<<endl;
}