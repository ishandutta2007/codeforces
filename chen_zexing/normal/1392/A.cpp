#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int f=0;
        for(int i=1;i<=n;i++) if(a[i]!=a[1]) f=1;
        if(f) printf("1\n");
        else printf("%d\n",n);
    }
    return 0;
}