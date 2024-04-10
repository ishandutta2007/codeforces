#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int qwq[1000003],ans;
map<pair<int,int>,int> mp;
void del(int x)
{
    if(!x) return ;
    ans-=max(0ll,a[x]-qwq[x]);
    --qwq[x];
    ans+=max(0ll,a[x]-qwq[x]);
}
void add(int x)
{if(!x) return ;
    ans-=max(0ll,a[x]-qwq[x]);
    ++qwq[x];
    ans+=max(0ll,a[x]-qwq[x]);
}
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read(),ans+=a[i];
    for(int T=read(); T--;)
    {
        int x=read(),y=read(),z=read();
        del(mp[make_pair(x,y)]);
        mp[make_pair(x,y)]=z;
        add(mp[make_pair(x,y)]);
        printf("%lld\n",ans);
    }
	return 0;
}