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
long long a[200005],b[200005],mx[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        for(int i=1;i<=n;i++){
            a[i]=b[i]+mx[i];
            mx[i+1]=max(mx[i],a[i]);
            printf("%lld ",a[i]);
        }
        puts("");
    }
    return 0;
}