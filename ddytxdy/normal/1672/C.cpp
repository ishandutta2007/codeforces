#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int T,n,a[N],mn,mx;
void solve(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  mn=0;mx=0;
  for(int i=2;i<=n;i++){
    if(a[i]!=a[i-1])continue;
    if(!mn)mn=i;
    mx=i;
  }
  if(mn==mx)puts("0");
  else printf("%d\n",max(mx-mn-1,1));
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}