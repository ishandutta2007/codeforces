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
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[i]=0;
        for(int i=1;i<=n;i++) cnt[a[i]]++,v[a[i]]=i;
        int f=0;
        for(int i=1;i<=n;i++)
            if(cnt[i]==1){
                f=1;
                printf("%d\n",v[i]);
                break;
            }
        if(!f) puts("-1");
    }
    return 0;
}