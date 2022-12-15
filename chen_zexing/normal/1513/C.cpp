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
int cnt[10],cnt2[10],ans[10][200005];
int main() {
    for(int i=0;i<=9;i++){
        memset(cnt,0,sizeof(cnt));
        cnt[i]++;
        for(int j=1;j<=200000;j++){
            for(int k=1;k<=9;k++) cnt2[k]=cnt[k-1];
            cnt2[0]=0;
            cnt2[0]+=cnt[9],cnt2[1]+=cnt[9];
            for(int k=0;k<=9;k++) cnt[k]=cnt2[k]%1000000007;
            for(int k=0;k<=9;k++) ans[i][j]=(ans[i][j]+cnt[k])%1000000007;
        }
    }
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<10;i++) cnt[i]=0;
        long long aans=0;
        while(n) aans+=ans[n%10][m],aans%=1000000007,n/=10;
        printf("%lld\n",aans%1000000007);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp