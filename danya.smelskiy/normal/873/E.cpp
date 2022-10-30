#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[100005];
int b[100005];
int dp[30005][15];
int sz[100005];
int q[100005];
inline bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
inline int getmax(int l,int r){
    int len=r-l+1;
    len=sz[len];
    return max(dp[l][len],dp[r-(1<<len)+1][len]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i) {
        b[i]=a[i].first-a[i+1].first;
    }
    for (int i=2;i<=n;++i)
        sz[i]=sz[i/2]+1;
    for (int i=1;i<=n;++i)
        dp[i][0]=b[i];
    for (int i=1;i<=sz[n];++i)
    for (int j=1;j<=n-(1<<i)+1;++j) {
        dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
    }
    int ans=-1e9;
    int pos1=0;
    int pos2=0;
    long long max1=-1e9;
    long long max2=-1e9;
    long long max3=-1e9;
    int ll=-1;
    for (int i=1;i<n;++i) {
        for (int j=i+1;j<n;++j) {
            if ((j-i)*2<i) continue;
            if (j-i>i*2) continue;
            int l=max(1,(max(i,j-i)+1)/2);
            int r=(min(i,j-i))*2;
            if (l>n-j) continue;
            r=min(r,n-j);
            if (l>r) continue;
            int res=getmax(j+l,j+r);
            if (b[i]>max1 || (b[i]==max1 && b[j]>max2) || (b[i]==max1 && b[j]==max2 && res>max3)) {
                max1=b[i];
                max2=b[j];
                max3=res;
                pos1=i;
                pos2=j;
                ll=j+l;
            }
        }
    }
    for (int i=1;i<=pos1;++i)
        q[a[i].second]=1;
    for (int i=pos1+1;i<=pos2;++i)
        q[a[i].second]=2;
    for (int i=pos2+1;i<=n;++i) {
        q[a[i].second]=3;
        if (i>=ll && b[i]==max3) break;
    }
    for (int i=1;i<=n;++i)
        if (!q[i]) cout<<"-1 "; else cout<<q[i]<<" ";
}