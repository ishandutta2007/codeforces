#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define MAXN 600000
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int a[1005],n,cnt=0;
int ans[2][1000];
struct node{
    int a,num;
    friend bool operator< (node x,node y)
    {
        return x.a<y.a;
    }
};
queue<int> q;
priority_queue<node> q2;

int main()
{
    n=read();for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=a[1];i++)q.push(1);
    for(int i=2;i<=n;i++)q2.push((node){a[i],i});
    while(!q.empty()&&n>1)
    {
        int u=q.front();q.pop();
        node v=q2.top();q2.pop();
        ans[0][++cnt]=u;ans[1][cnt]=v.num;
        for(int i=1;i<=v.a;i++)q.push(v.num);
        n--;
    }
    if(n!=1) return 0*puts("-1");printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[0][i],ans[1][i]);
    return 0;
}