#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,q,a[N];char s[N];
struct dat{
  int ans,sum;
}t[N*4];
dat merge(dat a,dat b){
  dat c;
  c.ans=a.ans+b.ans;
  c.sum=a.sum+b.sum;
  if(1ll*a.sum*b.sum<0)
    c.ans-=min(abs(a.sum),abs(b.sum));
  return c;
}
void build(int x,int l,int r){
  if(l==r){
    t[x]=(dat){abs(a[l]),a[l]};
    return;
  }
  int mid=(l+r)>>1;
  build(x<<1,l,mid);
  build(x<<1|1,mid+1,r);
  t[x]=merge(t[x<<1],t[x<<1|1]);
}
dat query(int x,int l,int r,int ql,int qr){
  if(l>=ql&&r<=qr)return t[x];
  int mid=(l+r)>>1;
  if(ql<=mid&&qr>mid)
    return merge(query(x<<1,l,mid,ql,qr),query(x<<1|1,mid+1,r,ql,qr));
  if(ql<=mid)return query(x<<1,l,mid,ql,qr);
  return query(x<<1|1,mid+1,r,ql,qr);
}
int main(){
  scanf("%d%d%s",&n,&q,s+1);
  for(int i=1;i<n;i++)
    if(s[i]!=s[i+1])a[i]=0;
    else if(s[i]=='1')a[i]=1;
    else a[i]=-1;
  if(n!=1)build(1,1,n-1);
  for(int i=1,l,r;i<=q;i++){
    scanf("%d%d",&l,&r);
    if(l==r)puts("1");
    else{
      r--;
      dat x=query(1,1,n-1,l,r);
      printf("%d\n",x.ans+1);
    }
  }
  return 0;
}