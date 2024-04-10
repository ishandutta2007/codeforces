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
int a[200005];
int pre[200005][205];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n+1;i++)
            for(int j=1;j<=200;j++)
                pre[i][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=200;j++)
                pre[i][j]=pre[i-1][j]+(a[i]==j);
        for(int i=1;i<=200;i++) ans=max(ans,pre[n][i]);
        for(int i=1;i<=200;i++){
            int l=1,r=n;
            for(int j=1;j<=pre[n][i]/2;j++){
                while(pre[l][i]<j) l++;
                while(pre[n][i]-pre[r-1][i]<j) r--;
                int mx=0;
                for(int k=1;k<=200;k++) mx=max(pre[r-1][k]-pre[l][k],mx);
                ans=max(ans,mx+j*2);
                //cout<<i<<" "<<l<<" "<<r<<" "<<mx<<" "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}