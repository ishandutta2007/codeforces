#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
pii v[N];
int a[N],n,S1,S2,flag=0;
int b[N],nxt[N],bl[N];
vector<int> ans1,ans2;

signed main()
{
    scanf("%lld%lld%lld",&n,&S1,&S2);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),v[i]=mk(a[i],i);
    sort(v+1,v+n+1); for(int i=1;i<=n;i++) a[i]=v[i].first; 
    if(S1>S2) swap(S1,S2),flag=1;
    for(int i=1;i<=n;i++) b[i]=(S1+a[i]-1)/a[i];
    for(int i=n;i>=1;i--) if(a[i]*(n-i+1)>=S2) bl[i]=1;
    int NXT=-1;
    for(int i=n;i>=1;i--)
    {
        if(bl[i]) NXT=i;
        nxt[i]=NXT;
    }
    int BL=0;
    for(int i=1;i<=n;i++)
    {
        if(i+b[i]>n) continue;
        int to=i+b[i];
        if(nxt[to]!=-1)
        {
            for(int j=i;j<=to-1;j++) ans1.push_back(v[j].second);
            for(int j=nxt[to];j<=n;j++) ans2.push_back(v[j].second);
            BL=1;
            break;
        }
    }
    if(BL)
    {
        puts("Yes");
        if(flag) swap(ans1,ans2);
        printf("%lld %lld\n",(int)ans1.size(),(int)ans2.size());
        for(int i=0;i<(int)ans1.size();i++) printf("%lld ",ans1[i]); cout<<endl;
        for(int i=0;i<(int)ans2.size();i++) printf("%lld ",ans2[i]); cout<<endl;
        return 0;
    }
    swap(S1,S2); flag^=1;
    for(int i=1;i<=n;i++) b[i]=(S1+a[i]-1)/a[i];
    for(int i=n;i>=1;i--) if(a[i]*(n-i+1)>=S2) bl[i]=1;
    NXT=-1;
    for(int i=n;i>=1;i--)
    {
        if(bl[i]) NXT=i;
        nxt[i]=NXT;
    }
    BL=0;
    for(int i=1;i<=n;i++)
    {
        if(i+b[i]>n) continue;
        int to=i+b[i];
        if(nxt[to]!=-1)
        {
            for(int j=i;j<=to-1;j++) ans1.push_back(v[j].second);
            for(int j=nxt[to];j<=n;j++) ans2.push_back(v[j].second);
            BL=1;
            break;
        }
    }
    if(BL)
    {
        puts("Yes");
        if(flag) swap(ans1,ans2);
        printf("%lld %lld\n",(int)ans1.size(),(int)ans2.size());
        for(int i=0;i<(int)ans1.size();i++) printf("%lld ",ans1[i]); cout<<endl;
        for(int i=0;i<(int)ans2.size();i++) printf("%lld ",ans2[i]); cout<<endl;
        return 0;
    }
    puts("No");
    return 0;
}