#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,p;
int count(LL x){int ret=0;while(x)ret++,x-=x&-x;return ret;}
int main(){
    cin>>n>>p;
    for(int i=1;i<=100;i++){
        LL dat=n-p*i;
        if(dat>=i&&count(dat)<=i)printf("%d\n",i),exit(0);
    }
    puts("-1");
}