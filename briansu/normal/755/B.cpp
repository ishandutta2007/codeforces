#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&x){cerr<<x<<endl;}
template<typename t,typename ...T> void _do(t &&x,T &&...tail){cerr<<x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e12);

set<string> st;
int main()
{
    ll n,m,lap=0;
    cin>>n>>m;
    REP(i,n){string s;cin>>s;st.insert(s);}
    REP(i,m)
    {
        string s;
        cin>>s;
        if(st.count(s))lap++;
    }
    debug(lap,n-lap/2,m-lap/2-lap%2);
    if(n-lap/2>m-lap/2-lap%2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}