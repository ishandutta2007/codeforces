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
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
set<int> st;
map<int,int> mp;
pii s[N];
int d[N],p[N];
bool cmp(pii a,pii b)
{
    return a.se<b.se;
}
int main()
{
    int D,n,m,i,d1,d2,a,b;
    LL ans=0;
    set<int>::iterator it;
    cin>>D>>n>>m;
    for(i=1;i<=m;i++)
        scanf("%d%d",&s[i].fi,&s[i].se);
    sort(s+1,s+1+m);
    s[0].fi=0,s[0].se=0;
    s[m+1].fi=D,s[m+1].se=INF;
    m++;
    for(i=1;i<=m;i++)
        if(s[i].fi-s[i-1].fi>n)
        {
            printf("-1\n");
            return 0;
        }
    for(i=0;i<=m;i++)
    {
        st.insert(s[i].fi);
        mp[s[i].fi]=i;
        p[i]=s[i].se;
        if(i<m)
            d[i]=s[i+1].fi-s[i].fi;
    }
    sort(s+1,s+1+m,cmp);
    for(i=m-1;i;i--)
    {
        it=st.find(s[i].fi);
        a=mp[*it];
        d2=d[a];
        it--;
        b=mp[*it];
        d1=d[b];
        //debug(a);
        //debug(b);
        //debug(d1);
        //debug(d2);
        if(d1+d2>n)
        {
            ans+=(LL)(d1+d2-n)*p[a];
            d[b]=n;
        }
        else
            d[b]=d1+d2;
        it++;
        st.erase(it);
        //debug(ans);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))