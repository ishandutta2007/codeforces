#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T,n,a[N],x;
void solve(){
  scanf("%d",&n);x=0;
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]),x+=~a[i]&1;
  puts(x&1?"errorgorn":"maomao90");
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}