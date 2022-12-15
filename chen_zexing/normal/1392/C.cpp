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
using namespace std;
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++) if(a[i]>a[i+1]) ans+=a[i]-a[i+1];
        printf("%lld\n",ans);
    }
    return 0;
}