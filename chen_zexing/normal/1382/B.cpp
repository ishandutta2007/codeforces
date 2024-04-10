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
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,t,cnt=0,f=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>1) f=1;
        }
        if(f==0)
        {
            if(n%2) printf("First\n");
            else printf("Second\n");
        }
        else
        {
            for(int i=1;i<=n&&a[i]==1;i++) cnt++;
            if(cnt%2) printf("Second\n");
            else printf("First\n");
        }
    }
    return 0;
}