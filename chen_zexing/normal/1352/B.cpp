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
        int n,k;
        scanf("%d%d",&n,&k);
        if(n-(k-1)>0&&(n-k+1)%2)
        {
            printf("YES\n");
            for(int i=1;i<k;i++) printf("1 ");
            printf("%d\n",n-k+1);
            continue;
        }
        if(n-2*(k-1)>0&&(n-2*k+2)%2==0)
        {
            printf("YES\n");
            for(int i=1;i<k;i++) printf("2 ");
            printf("%d\n",n-2*k+2);
            continue;
        }
        printf("NO\n");
    }
    return 0;
}