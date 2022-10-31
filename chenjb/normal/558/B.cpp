#include<cstdio>
#include<cstring>
#include<map>
#define maxvalue 1100000
#define maxn 110000
using namespace std;
map<int,int> q;
int a[maxn],l[maxvalue],r[maxvalue];
int maxa,ansl,ansr,n,ans,target;
void init()
{
  scanf("%d",&n);
  memset(l,0,sizeof(l));
  memset(r,0,sizeof(r));
  ans=0;
  maxa=0;
  for(int i=1;i<=n;i++)
  { 
    scanf("%d",&a[i]);
    ++q[a[i]];
    if (maxa<a[i]) maxa=a[i];
    if (q[a[i]]>ans) ans=q[a[i]];
    if (l[a[i]]==0) l[a[i]]=i;
    r[a[i]]=i;
  }
}
void work()
{
  ansl=1;
  ansr=n;
  for(int i=1;i<=n;i++)
  {
    int t=q[a[i]];
    if (t!=ans) continue;
    if (r[a[i]]-l[a[i]]<ansr-ansl) ansl=l[a[i]],ansr=r[a[i]];
  }
  printf("%d %d\n",ansl,ansr);
}
int main()
{

  init();
  work();
}