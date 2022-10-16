#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
inline int gcd(int a,int b){
    if (b==0)return a;
    return gcd(b,a%b);
}
inline int lcm(int a,int b){
    if (a==0||b==0)return 0;
    return a*b/gcd(a,b);
}
int n,a[100005],ans,mx;
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        scanf("%I64d",&a[i]),ans=max(ans,a[i]);
    sort(a+1,a+1+n);
    mx=1e18;
    for (int i=1;i<=10;i++){
        int flag=0;
        for (int j=n;j>=1;j--)
            if  (a[j]%2==0&&a[j]<mx){
                flag=1;
                mx=a[j];
                break;
            }
        if (flag==0)continue;
        for (int j=n;j>=1;j--)
            ans=max(ans,lcm(mx,a[j]));
    }
    mx=1e18;
    for (int i=1;i<=10;i++){
        int flag=0;
        for (int j=n;j>=1;j--)
            if  (a[j]%2==1&&a[j]<mx){
                flag=1;
                mx=a[j];
                break;
            }
        if (flag==0)continue;
        for (int j=n;j>=1;j--)
            ans=max(ans,lcm(mx,a[j]));
    }
    cout<<ans<<endl;
}