//  228

#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000009

int pre[51];
void seive(){
bool prime[51];
memset(prime,true,sizeof(prime));
for(int i=2;i*i<=50;++i){
    if(prime[i]==true){
        for(int p=i*i;p<=50;p+=i ){
            prime[p]=false;
        }
    }


}
pre[0]=0;
pre[1]=0;
for(int i=2;i<=50;++i){
    pre[i]=pre[i-1]+prime[i];
}
}
int answer(int n){
return pre[n];
}

int main(){
fastio
ll a,b,c;
cin>>a>>b>>c;
if(a&1){
    a=a+1;
}
if(b&1){
    b=b+1;
}
if(c&1){
    c=c+1;
}
ll ans=max((27+3*(a)/2),max((28+3*(b)/2),29+(3*(c)/2)));

cout<<ans;
return 0;
}