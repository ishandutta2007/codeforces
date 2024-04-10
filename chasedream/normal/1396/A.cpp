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
const int N=500005;
ll a[N];
int n;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  if(n==1){
    puts("1 1");
    printf("%lld ",-a[1]);
    puts("");
    puts("1 1"),puts("0");
    puts("1 1"),puts("0");
    return 0; 
  }
  printf("%d %d\n",1,n-1);
  for(int i=1;i<=n-1;i++){
    ll x=a[i]%n;
    printf("%lld ",1ll*x*(n-1));
    a[i]+=1ll*x*(n-1);
  } 
  puts("");
  printf("%d %d\n",n,n);
  printf("%lld ",-a[n]);
  puts("");
  printf("%d %d\n",1,n);
  for(int i=1;i<=n;i++){
    if(i==n){
      puts("0");continue;
    }
    printf("%lld ",-a[i]);
  }
  puts("");
  return 0;
}