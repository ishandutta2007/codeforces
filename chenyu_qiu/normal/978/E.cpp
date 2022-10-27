#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6+10;
const ll INF = 0x3f3f3f3f;
ll b[MAXN];
int main(){
   int n,w,a;
   cin>>n>>w>>b[0];
   ll max_z=0,max_f=0;
 
   if(b[0]<0) max_f = max(abs(b[0]),max_f);
   else max_z = max(abs(b[0]),max_z);
   
   for(int i=1;i<n;i++){
       cin>>a;
       b[i]+=b[i-1]+a;
       if(b[i]<0) max_f = max(abs(b[i]),max_f);
       else max_z = max(abs(b[i]),max_z);
   }
   if(max_f>w-max_z) cout<<0<<endl;
   else cout<<w-max_z-max_f+1<<endl;
}