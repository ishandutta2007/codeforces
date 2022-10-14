#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> a[100003],b[100003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i].first=read(),a[i].second=read();
    for(int i=1; i<=n; i++) b[i].first=read(),b[i].second=read();
    sort(a+1,a+n+1),sort(b+1,b+n+1);
    pair<int,int> ans=make_pair(a[1].first+b[n].first,a[1].second+b[n].second);
    printf("%lld %lld\n",ans.first,ans.second);
    return 0;
}