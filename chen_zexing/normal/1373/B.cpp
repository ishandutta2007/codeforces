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
long long ans[2000005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        char a[105];
        cin>>a;
        int x=0,y=0;
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]=='1') x++;
            else y++;
        }
        int k=min(x,y);
        if(k%2) printf("DA\n");
        else printf("NET\n");
    }
    return 0;
}