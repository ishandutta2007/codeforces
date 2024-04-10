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
int cnt[10000005];
int ans[10000005];
int main() {
    for(int i=1;i<=10000000;i++)
        for(int j=i;j<=10000000;j+=i)
            cnt[j]+=i;
    for(int i=10000000;i>=1;i--) if(cnt[i]<=10000000) ans[cnt[i]]=i;
    int T=1;
    cin>>T;
    while(T--){
        int c;
        scanf("%d",&c);
        printf("%d\n",ans[c]?ans[c]:-1);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp