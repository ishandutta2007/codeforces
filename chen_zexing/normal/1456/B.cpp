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
int pre[100005],a[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]^a[i];
    for(int i=3;i<=n;i++){
        if((a[i]^a[i-1])<a[i-2]||((a[i-1]^a[i-2])>a[i])){
            puts("1");
            return 0;
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<n-1;i++)
        for(int j=i+2;j<=n;j++)
            for(int k=i;k<j;k++)
                if((pre[k]^pre[i-1])>(pre[j]^pre[k]))
                    ans=min(ans,j-i-1);
    if(ans!=INT_MAX) cout<<ans;
    else puts("-1");
    return 0;
}