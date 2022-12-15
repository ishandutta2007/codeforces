#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define maxn 100005

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",a+b+c-1);
    }
}