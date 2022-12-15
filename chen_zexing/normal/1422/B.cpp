#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define maxn 100005

using namespace std;
int a[105][105];
bool cmp(int a,int b){return a<b;}
long long cal(int a,int b,int c,int d){
    vector <int> v;
    v.push_back(a);v.push_back(b);v.push_back(c);v.push_back(d);
    sort(v.begin(),v.end(),cmp);
    long long ans=0;
    for(int i=0;i<4;i++) ans+=abs(v[i]-v[1]);
    return ans;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        long long ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n/2;i++)
            for(int j=1;j<=m/2;j++)
                ans+=cal(a[i][j],a[n-i+1][j],a[i][m-j+1],a[n-i+1][m-j+1]);
        if(n%2){
            for(int j=1;j<=m/2;j++) ans+=abs(a[n/2+1][j]-a[n/2+1][m-j+1]);
        }
        if(m%2){
            for(int i=1;i<=n/2;i++) ans+=abs(a[i][m/2+1]-a[n-i+1][m/2+1]);
        }
        printf("%lld\n",ans);
    }
}