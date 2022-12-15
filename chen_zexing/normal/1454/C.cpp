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
int a[200005];
int cnt[200005],v[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cnt[i]=-1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]||i==n){
                if(cnt[a[i]]==-1) cnt[a[i]]=0;
                cnt[a[i]]++;
            }
        }
        int f=1;
        for(int i=1;i<=n;i++) if(a[i]!=a[1]) f=0;
        if(n==1||f){
            puts("0");
            continue;
        }
        cnt[a[1]]--,cnt[a[n]]--;
        int mn=INT_MAX;
        for(int i=1;i<=n;i++) if(cnt[i]!=-1) mn=min(mn,cnt[i]+1);
        printf("%d\n",mn);
    }
    return 0;
}