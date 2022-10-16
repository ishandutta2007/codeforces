#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int t,n1,n2,n3,a[1000005],b[1000005],c[1000005],x,y,ans=9e18;
inline int check(int x,int y,int z){
    return (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
}
signed main(){
    cin>>t;
    while(t--){
        cin>>n1>>n2>>n3;
        for (int i=1;i<=n1;i++)scanf("%lld",&a[i]);
        for (int i=1;i<=n2;i++)scanf("%lld",&b[i]);
        for (int i=1;i<=n3;i++)scanf("%lld",&c[i]);
        sort(a+1,a+1+n1);
        sort(b+1,b+1+n2);
        sort(c+1,c+1+n3);
        ans=9e18;
        x=y=0;
        for (int i=1;i<=n1;i++){
            while(x<n2&&b[x+1]<=a[i])x++;
            while(y<n3&&c[y+1]<=a[i])y++;
            if (x!=0&&y!=0)ans=min(ans,check(a[i],b[x],c[y]));
            if (x!=0&&y<n3)ans=min(ans,check(a[i],b[x],c[y+1]));
            if (x<n2&&y!=0)ans=min(ans,check(a[i],b[x+1],c[y]));
            if (x<n2&&y<n3)ans=min(ans,check(a[i],b[x+1],c[y+1]));
        }
        x=y=0;
        for (int i=1;i<=n2;i++){
            while(x<n1&&a[x+1]<=b[i])x++;
            while(y<n3&&c[y+1]<=b[i])y++;
            if (x!=0&&y!=0)ans=min(ans,check(a[x],b[i],c[y]));
            if (x!=0&&y<n3)ans=min(ans,check(a[x],b[i],c[y+1]));
            if (x<n1&&y!=0)ans=min(ans,check(a[x+1],b[i],c[y]));
            if (x<n1&&y<n3)ans=min(ans,check(a[x+1],b[i],c[y+1]));
        }
        x=y=0;
        for (int i=1;i<=n3;i++){
            while(x<n1&&a[x+1]<=c[i])x++;
            while(y<n2&&b[y+1]<=c[i])y++;
            if (x!=0&&y!=0)ans=min(ans,check(a[x],b[y],c[i]));
            if (x!=0&&y<n2)ans=min(ans,check(a[x],b[y+1],c[i]));
            if (x<n1&&y!=0)ans=min(ans,check(a[x+1],b[y],c[i]));
            if (x<n1&&y<n2)ans=min(ans,check(a[x+1],b[y+1],c[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}