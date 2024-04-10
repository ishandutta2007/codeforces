#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back 
#define fir first
#define sec second
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=1e6+5;
ll ans,n,r1,r2,r3,d;
ll a[N],fuck[N],f[N],s[N];
int main(){
  memset(f,0x3f,sizeof(f));
  f[1]=0;
  scanf("%lld%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    fuck[i]=min(r1+r2,(a[i]+2)*r1);
    s[i]=s[i-1]+fuck[i];
  }  
  for(int i=1;i<=n;i++){
    f[i+1]=min(f[i+1],f[i]+r1*a[i]+r3+d);
    f[n+1]=min(f[n+1],f[i]+d*(n-i)*2+s[n-1]-s[i-1]+min(r1*a[n]+r3,fuck[n]+2*d));
    if(i<n){
      if(i+2>n)f[i+2]=min(f[i+2],f[i]+d*3+fuck[i]+fuck[i+1]);
      else f[i+2]=min(f[i+2],f[i]+d*4+fuck[i]+fuck[i+1]);
    }
    if(i+2<=n){
      if(i+3>n)f[i+3]=min(f[i+3],f[i]+d*6+fuck[i]+fuck[i+1]+fuck[i+2]);
      else f[i+3]=min(f[i+3],f[i]+d*7+fuck[i]+fuck[i+1]+fuck[i+2]);
    }
  }
  printf("%lld\n",f[n+1]);
  return 0; 
}