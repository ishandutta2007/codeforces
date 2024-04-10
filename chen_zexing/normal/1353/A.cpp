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
    cin>>T;
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==1) printf("%d\n",0);
        else if(n==2) printf("%d\n",m);
        else printf("%d\n",2*m);
    }
    return 0;
}