#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e6+3;
const ll INF =2e15;

int divsior[maxn];
int a[maxn];
int maxx[300010<<2];
ll sum[300010<<2];

void pushup(int rt)
{
  maxx[rt] = max(maxx[rt<<1],maxx[rt<<1|1]);
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
  if(l==r) {
    maxx[rt] = sum[rt] = a[l];
    return ;
  }
  int mid = (l+r) >> 1;
  build(l,mid,rt<<1);
  build(mid+1,r,rt<<1|1);
  pushup(rt);
}

void update(int left,int right,int l,int r,int rt)
{
  if(maxx[rt] <= 2) return ;
  if(l==r) {
    maxx[rt] = sum[rt] = divsior[maxx[rt]];
    return;
  }
  int mid = (l+r)>>1;
  if(right <= mid) {
    update(left,right,l,mid,rt<<1);
  }
  else if(left > mid) {
    update(left,right,mid+1,r,rt<<1|1);
  }
  else {
    update(left,mid,l,mid,rt<<1);
    update(mid+1,right,mid+1,r,rt<<1|1);
  }
  pushup(rt);
}

ll query(int left ,int right,int l,int r,int rt)
{
  if(left == l && right == r) return sum[rt];
  int mid = (l+r)>>1;
  if(right <= mid) return query(left,right,l,mid,rt<<1);
  if(left > mid) return query(left,right,mid+1,r,rt<<1|1);
  return query(left,mid,l,mid,rt<<1) + query(mid+1,right,mid+1,r,rt<<1|1);
}

int main(int argc, char const *argv[]) {
  for(int i=1;i<=1e6;i++) {
    for(int j=i;j<=1e6;j+=i) {
      divsior[j]++;
    }
  }
  int n,m;
  // std::cin >> n >> m;
  scanf("%d%d", &n,&m);
  for(int i=1;i<=n;i++) {
    // std::cin >> a[i];
    scanf("%d", &a[i]);
    //replace a[i] with divsior[a[i]]
  }
  build(1,n,1);
  for(int i=1;i<=m;i++) {
    int type,l,r;
    // std::cin >> type >> l >> r;
    scanf("%d%d%d",&type,&l,&r);
    if(type==1) {
      update(l,r,1,n,1); //replace
    }
    else { // getsum
      std::cout << query(l,r,1,n,1) << '\n';
    }
  }

  return 0;
}