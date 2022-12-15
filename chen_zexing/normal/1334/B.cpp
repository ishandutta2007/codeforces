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
int a[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        long long tot=0;
        for(int i=n;i>=1;i--){
            if(tot+a[i]>=1LL*x*(n-i+1)) tot+=a[i],ans++;
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}