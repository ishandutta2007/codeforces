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

string s;
int len;
ll d[4]={0};
map<char,int> mp;
bool ck(ll a[])
{
    set<char> st;
    REP(i,4)if(s[a[i]]!='!')st.insert(s[a[i]]);else return 0;
    if(st.size()!=4)return 0;
    FILL(d,0);
    REP(i,len)
    {
        if(s[i]!=s[a[i%4]])d[mp[s[a[i%4]]]]++;
    }
    return 1;
}
int main()
{
    cin>>s;
    len=s.length();
    mp['R']=0;
    mp['B']=1;
    mp['Y']=2;
    mp['G']=3;
    for(int i=0;i<len;i+=4)
    {
        for(int j=1;j<len;j+=4)
        {
            for(int k=2;k<len;k+=4)
            {
                for(int l=3;l<len;l+=4)
                {
                    ll a[4]={i,j,k,l};
                    if(ck(a))
                    {
                        cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
                        return 0;
                    }
                }
            }

        }
    }

}