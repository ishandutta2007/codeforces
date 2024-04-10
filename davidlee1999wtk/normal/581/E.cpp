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
int s1[N],s2[N];
vector<int> pr,sp,sd;
int main()
{
    int e,s,n,m,x,t,f,i,n1=0,n2=0,n3=0,lim,loc,ans1,ans2,ans3;
    cin>>e>>s>>n>>m;
    for(i=1;i<=n+1;i++)
    {
        if(i==n+1)
            x=3,t=e;
        else
        {
            cin>>x>>t;
            if(t>=e) continue;
        }
        if(x==3)
            sp.push_back(t),n3++;
        if(x>=2)
            pr.push_back(t),n2++;
        sd.push_back(t),n1++;
    }
    //debug(n1);
    sort(sp.begin(),sp.end());
    sort(pr.begin(),pr.end());
    sort(sd.begin(),sd.end());
    for(i=n1-2;i>=0;i--)
        if(sd[i+1]-sd[i]>s)
        {
            lim=sd[i+1]-s;
            break;
        }
    if(i==-1)
        lim=sd[0]-s;
    //debug(lim);
    s2[n3-1]=0;
    for(i=n3-2;i>=0;i--)
        s2[i]=s2[i+1]+max(sp[i+1]-sp[i]-s,0);
    s1[n2-1]=0;
    for(i=n2-2;i>=0;i--)
        s1[i]=s1[i+1]+max(pr[i+1]-pr[i]-s,0);
    while(m--)
    {
        scanf("%d",&f);
        if(f<lim)
            printf("-1 -1\n");
        else
        {
            loc=lower_bound(sp.begin(),sp.end(),f)-sp.begin();
            ans2=(s2[loc]+max(sp[loc]-f-s,0));
            ans3=(e-f)-ans2;
            loc=lower_bound(pr.begin(),pr.end(),f)-pr.begin();
            ans1=s1[loc]+max(pr[loc]-f-s,0);
            ans2-=ans1;
            printf("%d %d\n",ans1,ans2);
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))