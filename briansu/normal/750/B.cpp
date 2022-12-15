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



ll n;
ll now=0;
int main()
{

    cin>>n;
    REP(i,n)
    {
        ll tmp;string s;
        cin>>tmp>>s;
        if((s[0]=='W'||s[0]=='E')&&(now==0||now==20000)){cout<<"NO"<<endl;return 0;}
        if(s[0]=='N')now-=tmp;
        if(s[0]=='S')now+=tmp;
        if(now<0||now>20000){cout<<"NO"<<endl;return 0;}
    }
    if(now!=0){cout<<"NO"<<endl;return 0;}
    else cout<<"YES"<<endl;

}