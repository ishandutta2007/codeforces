#include <bits/stdc++.h>
using namespace std;
long long n,ans,a[5];

int main(){
    cin>>n>>a[1]>>a[2]>>a[3];
    long long kol=4-(n%4);
    if (kol==4) kol=0;
    ans=kol*a[1];
    for (int i=0;i<=10;++i){
        for (int j=0;j<=10;++j){
            for (int k=0;k<=10;++k)
            if ((n+i+j*2+k*3)%4==0){
                ans=min(ans,(a[1]*i+a[2]*j+a[3]*k));
            }
        }
    }
    cout<<ans;
}