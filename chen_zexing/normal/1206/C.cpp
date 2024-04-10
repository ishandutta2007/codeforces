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
#include <string>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n%2==0) printf("NO\n");
    else{
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            if(i%2) printf("%d ",i*2-1);
            else printf("%d ",i*2);
        }
        for(int i=1;i<=n;i++)
        {
            if(i%2) printf("%d ",i*2);
            else printf("%d ",i*2-1);
        }
        printf("\n");
    }
}