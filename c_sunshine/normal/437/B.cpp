#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define lowbit(x) (x&(-x))
const int maxn=100005;
struct node
{
  int num;
  int val;
}p[maxn];
int sum,n;
int ans[maxn],tot;
bool cmp(node e1,node e2)
{return e1.val>e2.val;}
int main()
{
  int i;
  scanf("%d%d",&sum,&n);
  for(i=1;i<=n;i++)
    p[i].num=i,p[i].val=lowbit(i);
  sort(p+1,p+n+1,cmp);
  for(i=1;i<=n&&sum>0;i++)
    if(sum>=p[i].val)
    {
      sum-=p[i].val;
      ans[++tot]=p[i].num;
    }
  if(sum){printf("-1");return 0;}
  printf("%d\n",tot);
  for(i=1;i<tot;i++)
    printf("%d ",ans[i]);
  printf("%d",ans[tot]);
  return 0;
}