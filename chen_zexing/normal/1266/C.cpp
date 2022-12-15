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
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        if(n==m&&n==1){
            puts("0");
            continue;
        }
        if(m==1){
            for(int i=1;i<=n;i++) printf("%d\n",i+1);
            continue;
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d ",i*(j+n));
    }
    return 0;
}