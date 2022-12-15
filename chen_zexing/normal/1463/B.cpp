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
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,a[55];
        long long sum[2]={};
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i%2]+=a[i];
        if(sum[1]<=sum[0])
            for(int i=1;i<=n;i++)
                printf("%d ",i%2?1:a[i]);
        else for(int i=1;i<=n;i++) printf("%d ",i%2?a[i]:1);
        puts("");
    }
    return 0;
}