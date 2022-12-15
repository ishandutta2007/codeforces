#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int f[1000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        f[1]=1;
        for(int i=2;i<=1000000;i++)
            if(!f[i]){
                for(int j=i*2;j<=1000000;j+=i)
                    f[j]=1;
            }
        int now=n,p=0;
        for(int i=0;i<=n/2;i++)
            if(!f[now+i]){
                p=i;
                break;
            }
        printf("%d\n",now+p);
        for(int i=1;i<n;i++) printf("%d %d\n",i,i+1);
        printf("1 %d\n",n);
        for(int i=1;i<=p;i++) printf("%d %d\n",i,i+n/2);
    }
    return 0;
}