#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[400005],b[400005],tota,totb;
int n,num[400005],ans;
inline int calc1(int x){
    int j=tota,ans=0;
    for (int i=1;i<=tota;i++){
        j=max(j,i);
        while(i<j&&a[i]+a[j]>=x)j--;
        ans+=tota-j,ans%=2;
    }
    return ans;
}
inline int calc2(int x){
    int j=totb,ans=0;
    for (int i=1;i<=totb;i++){
        j=max(j,i);
        while(i<j&&b[i]+b[j]>=x)j--;
        ans+=totb-j,ans%=2;
    }
    return ans;
}
inline int calc3(int x){
    int j=totb,ans=0;
    for (int i=1;i<=tota;i++){
        while(j>0&&a[i]+b[j]>=x)j--;
        ans+=j,ans%=2;
    }
    return ans;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%d",&num[i]);
    for (register int i=0;i<=24;i++){
        tota=totb=0;
        for (register int j=1;j<=n;j++){
            if ((num[j]&(1<<i))==0)a[++tota]=num[j]%(1<<i);
            else b[++totb]=num[j]%(1<<i);
        }
        sort(a+1,a+1+tota);
        sort(b+1,b+1+totb);
        int cnt=calc1(1<<i)+calc2(1<<i)+calc3(1<<i);
        cnt%=2;
        if (cnt==1)ans+=(1<<i);
    }
    cout<<ans<<endl;
}