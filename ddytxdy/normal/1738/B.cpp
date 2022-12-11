#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;
const int N=2e5+50,mod=1e9+7,inv2=5e8+4;
const int M=1e5;
int T,n,k,a[N],s[N];
void solve(){
  scanf("%d%d",&n,&k);
  for(int i=n-k+1;i<=n;i++)
    scanf("%d",&s[i]);
  for(int i=n-k+2;i<=n;i++)
    a[i]=s[i]-s[i-1];
  a[n-k+1]=s[n-k+1]<0?(s[n-k+1]/(n-k+1)):((s[n-k+1]+n-k)/(n-k+1));
  bool fl=1;
  for(int i=n-k+2;i<=n;i++)
    fl&=a[i]>=a[i-1];
  puts(fl?"YES":"NO");
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}