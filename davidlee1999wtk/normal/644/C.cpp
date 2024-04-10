#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1020407
#define K1 233
#define K2 223
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<unsigned long long,int> pui;
map<string,int> map_s;
map<pui,int> map_h;
string fmp[N];
vector<pui> hs[N];
vector<int> gp[N];
pui get_hs(string s)
{
    int len=s.size(),i;
    unsigned long long V1=0,cf1=1;
    int V2=0,cf2=1;
    for(i=0;i<len;i++)
    {
        V1=V1*K1+s[i];
        //cf1*=K1;
        V2=((LL)V2*K2+s[i])%P;
        //cf2=cf2*K2%P;
    }
    //V1=V1*len;
    //V2=(LL)V2*len%P;
    //cout<<s<<endl;
    //debug(V1);
    //debug(V2);
    return MP(V1,V2);
}

pui get_hs2(int x)
{
    int len,i;
    unsigned long long V1=0,cf1=1;
    int V2=0,cf2=1;
    sort(hs[x].begin(),hs[x].end());
    len=unique(hs[x].begin(),hs[x].end())-hs[x].begin();
    //len=hs[x].size();
    //debug(x);
    //debug(len);
    for(i=0;i<len;i++)
    {
        //debug(hs[x][i].fi);
        //debug(hs[x][i].se);
        V1=V1*K2+hs[x][i].fi;
        V1=V1*K1+29;
        //cf1*=K1;
        V2=((LL)V2*K1+hs[x][i].se)%P;
        V2=((LL)V2*K2+29)%P;
        //debug(V2);
        //cf2=cf2*K2%P;
    }
    //V1=V1*len;
    //V2=(LL)V2*len%P;
    //debug(V1);
    //debug(V2);
    return MP(V1,V2);
}

int main()
{
    //ios::sync_with_stdio(false);
    int n,m=0,z=0,i,j,x,len;
    string address,hostname,path;
    pui t;
    cin>>n;
    while(n--)
    {
        cin>>address;
        address.insert(address.end(),'/');
        len=address.size();
        for(i=7;i<len;i++)
            if(address[i]=='/')
            {
                hostname=address.substr(0,(i-1)-0+1);
                path=address.substr(i,len-i-1);
                break;
            }
        //debug(address);
        //debug(hostname);
        //debug(path);
        if(!map_s[hostname])
        {
            map_s[hostname]=++m;
            fmp[m]=hostname;
        }
        x=map_s[hostname];
        hs[x].push_back(get_hs(path));
    }
    for(i=1;i<=m;i++)
    {
        t=get_hs2(i);
        //debug(t.fi);
        //debug(t.se);
        if(!map_h[t])
            map_h[t]=++z;
        gp[map_h[t]].push_back(i);
    }
    int ans=0;
    for(i=1;i<=z;i++)
        if(gp[i].size()>1)
            ans++;
    cout<<ans<<endl;
    for(i=1;i<=z;i++)
        if(gp[i].size()>1)
        {
            for(j=0;j<gp[i].size();j++)
                cout<<fmp[gp[i][j]]<<" ";
            cout<<endl;
        }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")