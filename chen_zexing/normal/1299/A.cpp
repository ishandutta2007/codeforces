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
int a[100005],b[100005],id[100005];
int cnt[35];
bool cmp(int x,int y){
    return b[x]>b[y];
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i;
        for(int i=1;i<=n;i++){
            int temp=a[i],now=0;
            while(temp) cnt[now++]+=temp%2,temp/=2;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++) if((a[i]&(1<<j))&&cnt[j]<2) b[i]+=(1<<j);
        }
        sort(id+1,id+n+1,cmp);
        for(int i=1;i<=n;i++) printf("%d ",a[id[i]]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp