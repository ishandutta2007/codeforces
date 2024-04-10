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
int cnt1[100005],cnt2[100005],a[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,mx1=0,mx2=1,tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt1[i]=cnt2[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]),cnt1[a[i]]++;
            if(i>1&&a[i]==a[i-1]) cnt2[a[i]]+=2,tot++;
            mx1=max(mx1,cnt1[a[i]]);
            mx2=max(mx2,cnt2[a[i]]);
        }
        cnt2[a[1]]++,cnt2[a[n]]++;
        mx2=max(mx2,max(cnt2[a[1]],cnt2[a[n]]));
        if(mx1>(n+1)/2) puts("-1");
        else printf("%d\n",tot+max(0,mx2-tot-2));
    }
    return 0;
}