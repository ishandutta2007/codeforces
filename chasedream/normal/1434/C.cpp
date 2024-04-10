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
#define mset(s,t) memset(s,t,sizeof(s))
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
int T,a,b,c,d;
ll S1(ll x){
  return x*(x+1)/2;
}
ll check(int n) {
  ll cur=1ll*a*(n+1),fuck=min(n,c/d);
  return cur-1ll*(n-fuck)*b*c-1ll*S1(fuck)*d*b;
}
void work(){
  a=read(),b=read(),c=read(),d=read();
  if(a>1ll*b*c){puts("-1");return ;}
  int l=1,r=1000005,ans=0;
  while(l<=r){
    int mid=l+r>>1;
    if(check(mid)>check(mid-1))l=mid+1,ans=mid;
    else r=mid-1;
  }
  printf("%lld\n",check(ans));
}
int main(){
  T=read();
  while(T--)work();
  return 0;
}