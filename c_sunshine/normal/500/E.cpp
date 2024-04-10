#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=400005;
int n,ans[maxn];
int p[maxn],l[maxn];
int A[maxn*4],nn;
struct node
{
  int siz;
  bool cov;
  node *lc,*rc;
}E[2000000],*root;
int ES;

node* build(int l,int r)
{
  node *cur=E+ES++;
  if(l==r)return cur;
  int mid=l+r>>1;
  cur->lc=build(l,mid);
  cur->rc=build(mid+1,r);
  return cur;
}

void Insert(node *cur,int l,int r,int a,int b)
{
  if(l>=a&&r<=b)
  {
    cur->siz=A[r]-A[l-1];
    cur->cov=1;
  }
  else
  {
    int mid=l+r>>1;
    if(cur->cov)return;
    if(a<=mid)Insert(cur->lc,l,mid,a,b);
    if(b>mid)Insert(cur->rc,mid+1,r,a,b);
    cur->siz=cur->lc->siz+cur->rc->siz;
  }
}

int query(node *cur,int l,int r,int a,int b)
{
  if(l>=a&&r<=b)return cur->siz;
  if(cur->cov)return A[min(r,b)]-A[max(l,a)-1];
  int mid=l+r>>1,ret=0;
  if(a<=mid)ret+=query(cur->lc,l,mid,a,b);
  if(b>mid)ret+=query(cur->rc,mid+1,r,a,b);
  return ret;
}

struct ask
{
  int id;
  int x,y;
}q[maxn];

bool cmpx(const ask &e1,const ask &e2)
{return e1.x<e2.x;}

int Find(int k)
{
  int low=0,high=nn,mid;
  while(low<=high)
  {
    mid=low+high>>1;
    if(A[mid]==k)return mid;
    if(A[mid]>k)high=mid-1;
    else low=mid+1;
  }
}

void add(int i)
{
  int a,b;
  a=Find(p[i]);
  b=Find(p[i]+l[i]);
  Insert(root,1,nn,a+1,b);
}

void init()
{
  scanf("%d",&n);
  int tn=0;
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d",p+i,l+i);
    A[++tn]=p[i];
    A[++tn]=p[i]+l[i];
  }
  sort(A+1,A+tn+1);
  for(int i=1;i<=tn;i++)
    if(A[nn]!=A[i])A[++nn]=A[i];
  root=build(1,nn);
}

void work()
{
  int Q;
  scanf("%d",&Q);
  for(int i=1;i<=Q;i++)
  {
    scanf("%d%d",&q[i].x,&q[i].y);
    q[i].id=i;
  }
  sort(q+1,q+Q+1,cmpx);
  for(int i=Q,j=n;i;i--)
  {
    while(j&&p[j]>=p[q[i].x])
      add(j--);
    ans[q[i].id]=p[q[i].y]-p[q[i].x]-query(root,1,nn,Find(p[q[i].x])+1,Find(p[q[i].y]));
  }
  for(int i=1;i<=Q;i++)
    printf("%d\n",ans[i]);
}

int main()
{
  init();
  work();
  return 0;
}