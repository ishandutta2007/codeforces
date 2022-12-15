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
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n>=2000){
            puts("0");
            continue;
        }
        long long ans=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=ans*(a[j]-a[i])%m;
        cout<<ans<<endl;
    }
    return 0;
}