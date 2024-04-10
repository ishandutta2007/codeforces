#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const long long mdn=998244353;

int n;

long long a[maxn],b[maxn],c[maxn];

bool cmp(long long a,long long b){return a>b;}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        c[i]=(long long)i*(long long)(n-i+1);
    }
    for(int i=1;i<=n;i++) a[i]*=c[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=(a[i]%mdn)*b[i];
        ans%=mdn;
    }
    cout<<ans;
    return 0;
}