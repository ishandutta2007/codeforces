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
#include <unordered_set>
#define hash hassh
using namespace std;
int ans[1000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        long long n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) ans[i]=i;
        if(k<1LL*(n+1)*n/2){
            puts("-1");
            continue;
        }
        long long rest=k-1LL*(n+1)*n/2;
        for(int i=1;i<=n/2;i++){
            int temp=(n-i+1)-i;
            if(temp>=rest){
                swap(ans[i],ans[i+rest]);
                rest=0;
                break;
            }
            swap(ans[i],ans[i+temp]);
            rest-=temp;
        }
        printf("%lld\n",k-rest);
        for(int i=1;i<=n;i++) printf("%d ",i);
        puts("");
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    }
    return 0;
}