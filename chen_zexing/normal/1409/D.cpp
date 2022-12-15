#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        scanf("%lld",&n);
        int s;
        scanf("%d",&s);
        int cnt=0;
        long long t=n;
        while(t){
            cnt+=t%10;
            t/=10;
        }
        if(cnt<=s){
            printf("0\n");
            continue;
        }
        int need=cnt-s+1,sum=0,p=0;
        t=n;
        while(sum<need){
            sum+=t%10;
            t/=10;
            p++;
        }
        long long k=1;
        for(int i=1;i<=p;i++) k*=10;
        printf("%lld\n",k-(n%k));
    }
    return 0;
}