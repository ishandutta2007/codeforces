#include<bits/stdc++.h>
using namespace std;

int n,d,m,p;
int a[100005];
long long pre[100005];

long long calc(int x){
    if(p+(long long)x*(d+1)<n||(long long)(x-1)*(d+1)+1>n)return 0;
    return pre[n]-pre[n-x]+pre[min(p,n-(x-1)*(d+1)-1)];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    p=upper_bound(a+1,a+1+n,m)-a-1;
    reverse(a+1,a+1+p);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    long long ans=0;
    for(int i=0;i<=n-p;i++){
        ans=max(ans,calc(i));
    }
    cout<<ans<<endl;

    return 0;
}