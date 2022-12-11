#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;
const int N=2e5+50,mod=998244353,inv2=5e8+4;
const int M=1e5;
int T,n,a[N],cnt,pw[N],ans,J[N],I[N];LL s[N];
map<LL,int>m;
int C(int n,int m){
  return 1ll*J[n]*I[m]%mod*I[n-m]%mod;
}
void solve(){
  scanf("%d",&n);m.clear();
  cnt=0;
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  for(int i=1;i<=n;i++)
    s[i]=s[i-1]+a[i];
  for(int i=1;i<n;i++){
    if(2*s[i]==s[n])cnt++;
    if(s[n]-s[i]<s[i])m[s[n]-s[i]]++;
  }
  ans=pw[cnt];
  for(int i=1,j=1;i<n;i++){
    while(j+1<n&&s[j+1]==s[i])j++;
    int x=j-i+1;
    if(s[n]-s[i]>s[i]&&m[s[i]]){
      int y=m[s[i]],z=0;
      for(int k=0;k<=min(x,y);k++)
        z=(z+1ll*C(x,k)*C(y,k))%mod;
      ans=1ll*ans*z%mod;
    }
    i=j;
  }
  printf("%d\n",ans);
}
int main(){
 // freopen("in.txt","r",stdin);
  pw[0]=1;J[0]=I[0]=I[1]=1;
  for(int i=2;i<N;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
  for(int i=1;i<N;i++)
    pw[i]=2*pw[i-1]%mod,J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod;
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}