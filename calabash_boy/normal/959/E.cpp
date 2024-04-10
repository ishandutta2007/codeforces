#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL bas[100];
int main(){
    cin>>n;
    bas[0]=1;
    for (int i=1;i<64;i++){
        bas[i] = bas[i-1]<<1;
    }
    LL ans =0;
    for (int i=0;i<64;i++){
        bool dig = n&bas[i];
        if (dig)ans+=bas[i];
    }
    for (int i=0;i<64;i++){
        bool dig = n&bas[i];
        if (dig){
            ans-=bas[i];
            break;
        }
    }
    for (int i=1;i<64;i++){
        bool dig = n&bas[i];
        if (dig){
            ans+=1LL*i*bas[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}