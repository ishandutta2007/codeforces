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
int ans[55][55];
int cnt[55];
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b||a>m||b>n){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans[i][j]=0,cnt[j]=0;
        int f1=gcd(n,b),f2=gcd(m,a);
        int aa=a/f2,bb=b/f1,nn=n/f1,mm=m/f2;
        for(int i=1;i<=nn;i++){
            int rest=aa;
            for(int j=i;rest;j=j%mm+1){
                if(cnt[j]<bb){
                    cnt[j]++;
                    ans[i][j]=1;
                    rest--;
                }
            }
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d",ans[i%nn+1][j%mm+1]);
    }
    return 0;
}