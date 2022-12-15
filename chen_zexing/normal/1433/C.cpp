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
int a[300005];
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
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++)
            if(mx<a[i]){
                mx=a[i];
                p=i;
            }
        if(p!=1||a[p]!=a[p+1]){
            printf("%d\n",p);
        }
        else{
            a[0]=a[n+1]=mx;
            for(int i=1;i<=n;i++)
                if(mx==a[i]&&(a[i]!=a[i-1]||a[i]!=a[i+1]))
                {
                    p=i;
                    break;
                }
            printf("%d\n",p);
        }
    }
    return 0;
}