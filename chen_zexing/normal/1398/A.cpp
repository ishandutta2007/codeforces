#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
long long a[100005];
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(a[n]>=a[1]+a[2]) printf("1 2 %d\n",n);
        else printf("-1\n");
    }
    return 0;
}