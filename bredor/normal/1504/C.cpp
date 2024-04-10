// 228
#include<bits/stdc++.h>
using namespace std;
int main(){long long i,j,k,m,n,x,y,t,mi,z;
string s,p;
cin>>t;
while(t>0){t=t-1;cin>>n>>s;x=0;char v[n],u[n];
for(i=0;i<n;i++){if(s[i]=='1')x=x+1;}
if((s[0]=='0'||s[n-1]=='0')||(x%2==1)){cout<<"NO"<<"\n";continue;}
cout<<"YES"<<"\n";y=0;
z=0;
for(i=0;i<n;i++){if(s[i]=='1'){if(z<x/2){z=z+1;u[i]='(';v[i]='(';}else{z=z+1;u[i]=')';v[i]=')';}}
else{if(y==1){y=0;u[i]='(';v[i]=')';}else{y=1;v[i]='(';u[i]=')';}}
}
for(i=0;i<n;i++){cout<<u[i];}cout<<"\n";
for(i=0;i<n;i++){cout<<v[i];}cout<<"\n";
}
return 0;}