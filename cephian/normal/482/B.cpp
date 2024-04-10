#include <iostream>

using namespace std;

const int N = 100005;

int segt[N<<2]={0};
int lazy[N<<2]={0};
int l[N<<2],r[N<<2];

void build(int v, int i, int j) {
  l[v]=i;
  r[v]=j;
  if(i==j) return;
  build(v*2,i,(i+j)/2);
  build(v*2+1,(i+j)/2+1,j);
}

int get(int v) {
  return segt[v]|lazy[v];
}

void prop(int v) {
  lazy[v*2] |= lazy[v];
  lazy[v*2+1]|= lazy[v];
  segt[v] |= lazy[v];
  lazy[v] = 0;
}

//assume lazy = 0
void refresh(int v) {
  segt[v] = get(v*2)&get(v*2+1);
}

void ud(int v, int i, int j, int a) {
  if(j < l[v] || r[v] < i) return;
  if(i <= l[v] && r[v] <= j) {
    lazy[v] |= a;
    return;
  }
  prop(v);
  ud(v*2,i,j,a);
  ud(v*2+1,i,j,a);
  refresh(v);
}

int qr(int v, int i, int j) {
  if(j < l[v] || r[v] < i) return -1;
  if(i <= l[v] && r[v] <= j) {
    return get(v);
  }
  prop(v);
  return qr(v*2,i,j)&qr(v*2+1,i,j);
}

int L[N],R[N],Q[N];

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  build(1,0,n-1);
  for(int i = 0; i < m; ++i) {
    scanf("%d%d%d",L+i,R+i,Q+i);
    ud(1,--L[i],--R[i],Q[i]);
  }
  for(int i = 0; i < m; ++i) {
    if(qr(1,L[i],R[i]) != Q[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for(int i = 0; i < n; ++i) {
    if(i) printf(" ");
    printf("%d",qr(1,i,i));
  }
  printf("\n");
}