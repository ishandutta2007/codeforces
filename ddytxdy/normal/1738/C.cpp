#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;
const int N=2e5+50,mod=1e9+7,inv2=5e8+4;
const int M=1e5;
int T,n,a0,a1;
void solve(){
  scanf("%d",&n);a1=a0=0;
  for(int i=1,x;i<=n;i++)
    scanf("%d",&x),a1+=x&1,a0+=~x&1;
  a1%=4;
  if(!a1)puts("Alice");
  else if(a1==1)puts(a0&1?"Alice":"Bob");
  else if(a1==2)puts("Bob");
  else puts("Alice");
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}