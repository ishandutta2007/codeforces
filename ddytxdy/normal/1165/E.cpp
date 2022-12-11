#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=2e5+50,mod=998244353;
int n;LL a[N],b[N],ans;
bool cmp(LL a,LL b){
    return a>b;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]*=1ll*i*(n-i+1);
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++)(ans+=a[i]%mod*b[i])%=mod;
    cout<<ans;
    return 0;
}