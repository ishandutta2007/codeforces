#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
int a[5005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,mx=0,p;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int f=0;
        for(int i=1;i<=n;i++) if(a[i]!=a[1]) f=1;
        if(!f){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1;i<=n;i++) if(a[i]!=a[1]){
                p=i;
                break;
            }
        for(int i=2;i<=n;i++) {
            if (a[i] != a[1]) {
                printf("1 %d\n", i);
            }
            else printf("%d %d\n",p,i);
        }

    }
    return 0;
}