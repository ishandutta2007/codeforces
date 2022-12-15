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
int a[2005],pre[2005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
        int f=0;
        for(int i=1;i<n;i++){
            if(pre[i]==(pre[n]^pre[i])) f=1;
            for(int j=i+1;j<n;j++) if((pre[i]==(pre[j]^pre[i]))&&(pre[i]==(pre[n]^pre[j]))) f=1;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp