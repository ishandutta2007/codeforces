#include<bits/stdc++.h>
using namespace std;
typedef bitset<120> B;
int m,t,x,M=1e9+7,c[120],a;
int dfs(int k,B b,int s){
if(k>m/2)a=(a+s)%M;else{
dfs(k+1,b,s);
c[k]&&!b[k]&&dfs(k+1,b|b<<m-k|b>>k|b<<k|b>>m-k,1LL*s*c[k]%M);
}}
int main(){
for(cin>>x>>m>>t;t--;c[min(x%m,m-x%m)]++)cin>>x;
dfs(1,B(1),1);cout<<a;
}