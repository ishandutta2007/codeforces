#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        int ans=0,copy=n;
        while(copy)
        {
            if(copy%10) ans++;
            copy/=10;
        }
        printf("%d\n",ans);
        int last=1;
        while(n)
        {
            if(n%10) printf("%d ",last*(n%10));
            last*=10;
            n/=10;
        }
        printf("\n");
    }
    return 0;
}