#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;
const int N=2e5+50,mod=1e9+7,inv2=5e8+4;
const int M=1e5;
int T,n,a[N],b[N],n1,n2;LL sum;
vector<int>v1,v2;
void solve(){
  scanf("%d",&n);n1=0;n2=0;
  v1.clear();v2.clear();sum=0;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    if(a[i]==0)n1++;else n2++;
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]);sum+=b[i];
    if(a[i]==0)v1.pb(b[i]);
    else v2.pb(b[i]);
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  if(n1==n2){
    printf("%lld\n",2*sum-min(v1[0],v2[0]));
  }
  else{
    int nn=min(n1,n2);sum*=2;
    for(int i=0;i<(int)v1.size()-nn;i++)
      sum-=v1[i];
    for(int i=0;i<(int)v2.size()-nn;i++)
      sum-=v2[i];
    printf("%lld\n",sum);
  }
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}