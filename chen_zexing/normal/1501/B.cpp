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
int a[200005],f[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=0;
        int now=n,low=n+1;
        while(now){
            low=min(low,now-a[now]+1);
            if(now>=low) f[now]=1;
            now--;
        }
        for(int i=1;i<=n;i++) printf("%d ",f[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 