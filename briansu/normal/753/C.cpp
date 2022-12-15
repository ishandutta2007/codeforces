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


string ans="0123";
//set<int> st;
vector<string> dt,tmpdt;
ii ck(string s)
{
    ll a=0,b=0;
    REP(i,4)if(s[i]==ans[i])a++;
    REP(i,4)
    {
        bool bl=0;
        REP(j,4)if(s[j]==ans[i])bl=1;
        b+=bl;
    }
    b-=a;
    return ii(a,b);
}
int main()
{
    srand(time(NULL));
    REP(i,10)
    {
        REP(j,10)
        {
            REP(k,10)
            {
                REP(l,10)
                {
                    if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
                    {
                        stringstream ss;
                        ss<<i<<j<<k<<l;
                        string s;
                        ss>>s;
                        dt.pb(s);
                        //st.insert(dt.size()-1);
                    }
                }
            }
        }
    }
    //debug(st.size());
    while(1)
    {
        ll i=rand()%dt.size();
        ans=dt[i];
        cout<<ans<<endl;
        ll a,b;
        cin>>a>>b;
        if(a==4&&b==0)return 0;
        tmpdt.resize(0);
        for(string s:dt)
        {
            ii tmp=ck(s);
            if((tmp.X==a&&tmp.Y==b))tmpdt.pb(s);
        }
        dt=tmpdt;  
    }

}