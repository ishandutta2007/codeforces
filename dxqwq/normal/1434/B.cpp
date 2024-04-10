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
char ch[200003][4];
int a[200003];
int ans[100003];
signed main()
{
    int n=read();
    for(int i=1; i<=2*n; i++)
    {
        scanf("%s",ch[i]);
        if(ch[i][0]=='-') a[i]=read();
    }
    priority_queue<int,vector<int>,greater<int> > q;
    int cnt=0;
    for(int i=2*n; i>=1; i--)
    {
        if(ch[i][0]=='+') 
        {
            if(q.empty()) puts("NO"),exit(0);
            ans[++cnt]=q.top(),q.pop();
        }
        else
        {
            if(!q.empty() && a[i]>=q.top()) puts("NO"),exit(0);
            q.push(a[i]);
        }
    }
    puts("YES");
    for(int i=n; i>=1; i--) printf("%lld ",ans[i]);
    return 0;
}