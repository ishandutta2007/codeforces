#include<bits/stdc++.h>
#define iter(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) iter(i,0,a)
#define rep1(i,a) iter(i,1,(a)+1)
using namespace std;
const uint64_t mask=3952873730080618203,mag1=5270498306774157604;
void fmt(uint64_t*a,int l){rep(i,l)for(int j=1<<i;j<(1<<l);j=(j+1)|(1<<i))a[j]=(a[j]+a[j^(1<<i)])&mask;}
uint64_t k1[1<<21],k2[1<<21];
int main() {
int l;cin>>l;
int n=1<<l;
string a,b;cin>>a>>b;
rep(i,n)k1[i]=a[i]-'0',k2[i]=b[i]-'0';
rep(i,n)k1[i]<<=(3*__builtin_popcountll(i)),k2[i]<<=(3*__builtin_popcountll(i));
fmt(k1,l);fmt(k2,l);
rep(i,n){uint64_t t=0;
rep(j,l+1){
int v=(k1[i]>>(3*j))%4;
if(v==1)t=(t+(k2[i]<<(3*j)))&mask;
if(v==2)t=(t+((k2[i]<<(3*j+1))&mask))&mask;
if(v==3)t=(t+((mag1-(k2[i]<<(3*j)))&mask))&mask;
}k1[i]=t;
}
rep(i,l)for(int j=1<<i;j<n;j=(j+1)|(1<<i))k1[j]=(mag1-k1[j^(1<<i)]+k1[j])&mask;
rep(i,n-1)putchar('0'+(k1[i]>>(3*__builtin_popcount(i)))%4);
long long sm=0;
rep(i,n)sm+=(a[i]-'0')*(b[(n-1)^i]-'0');
putchar('0'+sm%4);
putchar('\n');
}