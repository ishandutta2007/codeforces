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
int a[10][105],mx[105],id[105],r[10][10];
bool cmp(int a,int b){
    return mx[a]>mx[b];
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++) id[i]=i,mx[i]=0;
        for(int i=0;i<n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]),mx[j]=max(mx[j],a[i][j]);
        sort(id+1,id+m+1,cmp);
        //for(int i=1;i<=m;i++) cout<<id[i]<<" ";puts("");
        for(int i=0;i<pow(n,min(n,m));i++){
            int t=i;
            for(int j=1;j<=min(n,m);j++){
                int temp=t%n;
                t/=n;
                for(int k=0;k<n;k++) r[k][j]=a[(k+temp)%n][id[j]];
            }
            int now=0;
            for(int j=0;j<n;j++) {
                int temp=0;
                for (int k=1;k<=min(n,m);k++) temp=max(temp,r[j][k]);
                now+=temp;
            }
            ans=max(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp