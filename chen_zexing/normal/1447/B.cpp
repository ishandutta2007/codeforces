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
int b[105];
bool cmp(int a,int b){
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m,a[15][15],x=0,cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                scanf("%d", &a[i][j]), b[++x] = abs(a[i][j]);
                if (a[i][j] < 0) cnt++;
            }
        sort(b+1,b+n*m+1,cmp);
        if(cnt%2){
            int sum=-b[1];
            for(int i=2;i<=n*m;i++) sum+=b[i];
            printf("%d\n",sum);
        }
        else{
            int sum=0;
            for(int i=1;i<=n*m;i++) sum+=b[i];
            printf("%d\n",sum);
        }
    }
    return 0;
}