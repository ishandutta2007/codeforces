#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,n;
ll lowbit(ll x){
    return x&(-x);
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(lowbit(n)==n){
            printf("NO\n");
        }else printf("YES\n");
    }
    
    return 0;
}