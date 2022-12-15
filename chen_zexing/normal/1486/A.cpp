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
long long pre[105];
int a[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        int f=1;
        for(int i=1;i<=n;i++){
            if(pre[i]<1LL*i*(i-1)/2) f=0;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}