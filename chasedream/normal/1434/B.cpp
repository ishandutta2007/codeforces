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
const int N=500005;
int stk[N],len;
int tag[N],idx;
int flag[N],cnt[N];
int n;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=2*n;i++){
    char c=getchar();
    while(c!='-'&&c!='+'){
      c=getchar();
    }
    if(c=='+'){
      stk[++len]=++idx;
    }else{
      int x;scanf("%d",&x);
      if(len==0){
        puts("NO");return 0;
      }
      if(flag[x]){
        puts("NO");return 0;
      }
      flag[x]=1;
      if(tag[stk[len]]>x){
        puts("NO");return 0;
      }
      tag[stk[len--]]=x;
      tag[stk[len]]=max(tag[stk[len]],tag[stk[len+1]]);
    }
  }
  for(int i=1;i<=n;i++)cnt[tag[i]]++;
  for(int i=n;i>=0;i--)cnt[i]+=cnt[i+1];
  for(int i=n;i>=0;i--){
    if(cnt[i]>n-i+1){
      puts("NO");return 0;
    }
  }
  puts("YES");
  for(int i=1;i<=n;i++)
    printf("%d ",tag[i]);
  puts("");
}