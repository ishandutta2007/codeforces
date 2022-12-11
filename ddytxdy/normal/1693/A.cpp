#include<cmath>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N=2e5+50;
int T,ans,n,a[N];long long s;
void solve(){
  scanf("%d",&n);s=0;
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]),s+=a[i];
  if(s){puts("No");return;}
  bool fl=0;
  for(int i=1;i<=n;i++)if(a[i])fl=1;
  if(!fl){puts("Yes");return;}
  a[1]--;
  for(int i=n;i;i--)if(a[i]){a[i]++;break;}
  for(int i=1;i<=n;i++){
    s+=a[i];
    if(s<0){puts("No");return;}
  }
  puts("Yes");
  // if(a[1]<=0){puts("No");return;}
  // int i=1,j=n;
  // while(i<=j){
  //   while(i<=j&&!a[i])i++;
  //   while(i<=j&&!a[j])j++;
  //   if(a[i])
  // }

  // a[n+1]=0;
  // for(int i=n;i>2;i--){
  //   if(!a[i])continue;
  //   if(a[i]>0||a[i]+a[i-1]>=0){puts("No");return;}
  //   a[i-1]+=a[i];
  // }
  // if(a[1]+a[2]!=0||a[1]<=0){puts("No");return;}
  // puts("Yes");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}