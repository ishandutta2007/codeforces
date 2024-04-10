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
int cnt1[3005][3005],cnt2[3005][3005],a[3005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cnt1[i][j]=cnt2[i][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                cnt1[i][a[j]]++;
        for(int i=n;i>=1;i--)
            for(int j=n;j>i;j--)
                cnt2[i][a[j]]++;
        long long ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans+=cnt1[i][a[j]]*cnt2[j][a[i]];
        cout<<ans<<endl;
    }
    return 0;
}