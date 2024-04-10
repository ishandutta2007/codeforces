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
    int T;
    cin>>T;
    while(T--)
    {
        int x,n,m;
        cin>>x>>n>>m;
        while(x&&n)
        {
            if(x/2+10>x) break;
            x=x/2+10;
            n--;
        }
        if(x<=m*10) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}