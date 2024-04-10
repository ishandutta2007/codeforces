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
const int N=600005;

struct node{
  int typ,x;
  friend bool operator < (const node&x,const node&y){
    return x.x<y.x;
  } 
}c[N];

int a[N],b[N];
int n,m,tot;
int cnt[N];

int main(){
  n=6;
  for(int i=1;i<=n;i++)a[i]=read();
  m=read();
  for(int i=1;i<=m;i++)b[i]=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      tot++,c[tot]={j,b[j]-a[i]};
    }
  }
  sort(c+1,c+tot+1);
  int num=0,ans=2e9;
  /*
  for(int i=1;i<=tot;i++){
    printf(">> i=%d, %d %d\n",i,c[i].typ,c[i].x);
  }
  */
  for(int l=1,r=1;l<=tot;l++){
    if(l>1){
      if(--cnt[c[l-1].typ]==0)num--;
    }
    while(r<=tot&&num!=m){
      if(cnt[c[r].typ]++==0)num++;
      r++;
    }
    if(r<=tot)ans=min(ans,c[r-1].x-c[l].x);
    //printf("l=%d, r=%d\n",l,r); 
  }
  printf("%d\n",ans);
  return 0;
}