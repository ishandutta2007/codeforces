#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,cnt;
ll a[1000005],b[1000005],sum;

int main(){

    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=i-1;
        sum-=i-1;
    }
    for(int i=1;i<=n;i++){
        b[i]+=sum/n;
    }
    sum%=n;
    for(int i=1;i<=sum;i++)b[i]++;
    for(int i=1;i<=n;i++){
        printf("%lld ",b[i]);
    }

    return 0;
}