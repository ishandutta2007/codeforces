#include <bits/stdc++.h>

using namespace std;

const int N=(int)2e5+7;
int n,a[N];

void solve(int l,int r) {
  if (l>r) {
    return;
  }
  cout<<"? "<<l<<" "<<r<<endl;
  int x,len;
  cin>>x>>len;
  int l2=r-len+1,r2=l+len-1;
  if (l2<=r2) {
    for (int j=l2;j<=r2;j++) {
      a[j]=x;
    }
    solve(l,l2-1);
    solve(r2+1,r);
  } else {
    int m=(l+r)/2;
    solve(l,m);
    solve(m+1,r);
  }
}

int main() {
  cin>>n;
  solve(1,n);
  printf("! ");
  for (int i=1;i<=n;i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}