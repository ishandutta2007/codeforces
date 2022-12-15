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
int a[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        if(k>(n-1)/2){
            puts("-1");
            continue;
        }
        int now=n;
        for(int i=1;i<=n;i++) a[i]=0;
        for(int i=2;i<=k*2;i+=2) a[i]=now--;
        for(int i=1;i<=n;i++) if(!a[i]) a[i]=now--;
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp