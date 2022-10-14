#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
pair<int,int> a[1000003];
int ans[1000003];
int id[1000003];
signed main()
{
    int n=read(),l=read(),r=read();
    for(int i=1; i<=n; i++) a[i].second=read();
    for(int i=1; i<=n; i++) a[i].first=read(),id[a[i].first]=i;
    sort(a+1,a+n+1);
    ans[id[a[1].first]]=l;
    int lst=l-a[1].second+1;
    for(int i=2; i<=n; i++) 
    {
        ans[id[a[i].first]]=max(l,lst+a[i].second);
        if(ans[id[a[i].first]]>r) puts("-1"),exit(0);
        lst=max(lst,ans[id[a[i].first]]-a[i].second)+1;
    }
    for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
    return 0;
}