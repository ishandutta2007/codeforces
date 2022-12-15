#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#define LL long long
#define MAX 100005

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int a,b,c,d;
        if(m%2){
            for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a,&b,&c,&d);
            printf("NO\n");
            continue;
        }
        int f=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(b==c) f=1;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}