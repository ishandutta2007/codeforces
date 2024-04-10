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
#include <bitset>
#include <vector>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n==44) printf("YES\n6 10 15 13\n");
        else if(n==40) printf("YES\n6 14 15 5\n");
        else if(n==36) printf("YES\n6 10 15 5\n");
        else if(n>=31) printf("YES\n6 10 14 %d\n",n-30);
        else printf("NO\n");
    }
}