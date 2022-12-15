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
int a[1005],cnt[1005];
long long c[1005][1005];
int main() {
    c[0][0]=c[1][0]=c[1][1]=1;
    for(int i=2;i<=1000;i++)
        for(int j=0;j<=i;j++){
            if(j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
        }
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=n;i>=1;i--){
            if(cnt[i]<k) k-=cnt[i];
            else{
                printf("%lld\n",c[cnt[i]][k]);
                break;
            }
        }
    }
    return 0;
}