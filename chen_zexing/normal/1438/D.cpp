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
#define hash hassh
using namespace std;
int a[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n%2){
        puts("YES");
        printf("%d\n",n-2);
        for(int i=1;i<=n-2;i+=2) printf("%d %d %d\n",i,i+1,i+2);
        for(int i=1;i<=n-4;i+=2) printf("%d %d %d\n",i,i+1,n-2);
    }
    else{
        int f=1;
        for(int i=0;i<=30;i++) {
            int cnt=0;
            for(int j=1;j<=n;j++)
                if ((1 << i)&a[j])
                    cnt++;
            if(cnt%2){
                f=0;
                break;
            }
        }
        if(!f) puts("NO");
        else{
            puts("YES");
            if(n>4) {
                printf("%d\n", n - 4);
                printf("%d %d %d\n", n - 2, n - 1, n);
                n -= 3;
                for (int i = 1; i <= n - 2; i += 2) printf("%d %d %d\n", i, i + 1, i + 2);
                for (int i = 1; i <= n - 4; i += 2) printf("%d %d %d\n", i, i + 1, n - 2);
            }
            else{
                printf("1\n");
                printf("1 2 3\n");
            }
        }
    }
    return 0;
}