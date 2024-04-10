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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

bool not_equ(int *ra,int a,int b,int k,int n)
{
  return ra[a]!=ra[b]||a+k>=n||b+k>=n||ra[a+k]!=ra[b+k];
}
void radix(int *box,int *key,int *it,int *ot,int m,int n)
{
  fill_n(box,m,0);
  for(int i=0;i<n;i++)box[key[i]]++;
  partial_sum(box,box+m,box);
  for(int i=n-1;i>=0;--i)ot[--box[key[it[i]]]]=it[i];
}
void make_sa(int *sa,int *ra,const char *s,int n)
{
  static int box[MAXn],tp[MAXn];
  copy_n(s,n,ra);
  int k=1,m=256;
  do{
    iota(tp,tp+k,n-k);
    iota(sa+k,sa+n,0);
    radix(box,ra+k,sa+k,tp+k,m,n-k);
    radix(box,ra+0,tp+0,sa+0,m,n-0);
    tp[sa[0]]=0,m=1;
    for(int i=1;i<n;i++)
    {
      m+=not_equ(ra,sa[i],sa[i-1],k,n);
      tp[sa[i]]=m-1;
    }
    copy_n(tp,n,ra);
    k*=2;
  }while(k<n&&m!=n);
}
void make_he(int *he,int *sa,int *ra,const char *s,int n)
{
  for(int j=0,k=0;j<n;j++)
  {
    if(ra[j]){
      for(;s[j+k]==s[sa[ra[j]-1]+k];++k);
    }
    he[ra[j]]=k;
    k=max(0,k-1);
  }
}

char s[MAXn];
int sa[MAXn],ra[MAXn],he[MAXn];

stack<ii> st;

int main()
{
    IOS();
    ll T;
    cin>>T;
    while(T--&&cin>>s)
    {
        int n=strlen(s);
        make_sa(sa,ra,s,n);
        make_he(he,sa,ra,s,n);
        //pary(he+1,he+n+1);
        //pary(sa,sa+n);
        while(SZ(st))st.pop();
        st.push(ii(0,-1));
        int *h=he+1;
        ll ans=0;
        REP(i,n)
        {
          ans+=max(0LL,(n-sa[i])-max(ll(h[i]),st.top().X));
          //debug(i,ans);
          while(SZ(st))
          {
            if(st.top().X<h[i])
            {
              st.push(ii(h[i],i));
              break;
            }
            else if(st.top().X==h[i])break;
            else
            {
              ii tmp=st.top();
              st.pop();
              if(st.top().X>=h[i])ans+=(i-tmp.Y+1)*(i-tmp.Y+1)*(tmp.X-st.top().X);
              else
              {
                ans+=(i-tmp.Y+1)*(i-tmp.Y+1)*(tmp.X-h[i]);
                st.push(ii(h[i],tmp.Y));
              }

            }
          }
          //debug(i,ans,h[i]);
        }
        cout<<ans<<endl;

        FILL(sa,0);FILL(ra,0);
        FILL(s,0);FILL(he,0);
    }
}