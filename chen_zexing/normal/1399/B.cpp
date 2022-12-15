#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <cstring>
using namespace std;
int a[55],b[55];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long ans=0;
        int n,mna=INT_MAX,mnb=INT_MAX;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            mna=min(mna,a[i]);
            mnb=min(mnb,b[i]);
        }
        for(int i=1;i<=n;i++) ans+=max(a[i]-mna,b[i]-mnb);
        printf("%lld\n",ans);

    }
    return 0;
}