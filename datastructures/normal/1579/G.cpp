#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,a[10005];
bool f[10005][2005];
bool check(int x){
for (int i=0;i<=x;i++)f[0][i]=1;
for (int i=1;i<n;i++)
for (int j=0;j<=x;j++)f[i][j]=0;
int fg=1;
for (int i=0;i<n&&fg;i++){
fg=0;
for (int j=0;j<=x;j++){
if (f[i][j]==0)continue;
if (j+a[i+1]<=x)f[i+1][j+a[i+1]]=1,fg=1;
if (j-a[i+1]>=0)f[i+1][j-a[i+1]]=1,fg=1;
}
if (fg==0)return 0;
}
return 1;
}
int main(){
cin>>t;
while(t--){
cin>>n;
for (int i=1;i<=n;i++)cin>>a[i];
int l=1,r=2000,ans=0;
while(l<=r){
int mid=(l+r)/2;
if (check(mid))ans=mid,r=mid-1;
else l=mid+1;
}
cout<<ans<<endl;
}
}