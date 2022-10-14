#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
map<int,int>v;
int qpow(int b,int e){
int ans=1;while(e){
if(e&1)ans=1ll*ans*b%MOD;
b=1ll*b*b%MOD;e>>=1;
}return ans;}
int f[100005],iq[100005];
int res[100005],x[100005],y[100005];
int main() {
int n;cin>>n;
f[0]=iq[0]=1;
for(int i=1;i<=n;i++){f[i]=1ll*f[i-1]*i%MOD;iq[i]=qpow(f[i],MOD-2);}
for(int _=0;_<n;_++){
int x;cin>>x;
int z=1;
for(int i=2;i*i<=x;i++){
if(x%i)continue;
int d=0;while(x%i==0){d++,x/=i;}
if(d%2)z*=i;
}
z*=x;
v[z]++;
}
int li=1;res[0]=1;
for(auto[_,b]:v){
int z=1;
for(int i=0;i<b;i++){
x[i]=1ll*z*iq[i]%MOD;
z=1ll*z*(b-i)*(b-i-1)%MOD;
}
for(int i=0;i<li+b-1;i++)y[i]=0;
for(int i=0;i<b;i++)for(int j=0;j<li;j++)y[i+j]=(y[i+j]+1ll*x[i]*res[j])%MOD;
li+=b-1;for(int i=0;i<li;i++)res[i]=y[i];
}
int ans=0;
for(int i=0;i<li;i++){res[i]=1ll*res[i]*f[n-i]%MOD;(ans+=(i%2)?(MOD-res[i]):(res[i]))%=MOD;}
cout<<ans<<endl;
}