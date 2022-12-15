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
#include <map>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,x,a,b;
        scanf("%d%d",&n,&x);
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a==x||b==x) cnt++;
        }
        if(cnt<=1||n%2==0) printf("Ayush\n");
        else printf("Ashish\n");
    }
    return 0;
}