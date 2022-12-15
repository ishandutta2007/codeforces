#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
int a[105],cnt[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k,t=0;
        cin>>n>>k;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]),cnt[a[i]]++;
            if(cnt[a[i]]==1) t++;
        }
        if(k==1){
            if(t==1) printf("1\n");
            else printf("-1\n");
            continue;
        }
        if(k>=t){
            printf("1\n");
            continue;
        }
        t-=k;
        k--;
        printf("%d\n",t/k+(t%k>0)+1);
    }
    return 0;
}