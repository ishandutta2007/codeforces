#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define maxn 100005

using namespace std;
long long take(long long &x){
    if(x%2||(x%4==0&&x!=4)){
        x--;
        return 1;
    }
    else{
        x/=2;
        return x;
    }
}
int main() {
    int T;
    cin>>T;
    while(T--){
        long long n,ans=0;
        scanf("%lld",&n);
        while(n){
            ans+=take(n);
            if(!n) break;
            take(n);
        }
        printf("%lld\n",ans);
    }
}