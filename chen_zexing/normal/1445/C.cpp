#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a%b){
            printf("%lld\n",a);
            continue;
        }
        int f=0,i;
        long long t=b;
        long long ans=0;
        for(i=2;i*i<=b;i++) {
            if (b % i == 0) {
                int cnt=0;
                while(b%i==0) b/=i,cnt++;
                long long p=a;
                while(p%i==0) p/=i;
                cnt--;
                while(cnt--) p*=i;
                ans=max(ans,p);
            }
        }
        if(b>1){
            while(a%b==0) a/=b;
            ans=max(ans,a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}