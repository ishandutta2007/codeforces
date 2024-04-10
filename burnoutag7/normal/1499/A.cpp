#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,k1,k2,w,b;
    cin>>n>>k1>>k2>>w>>b;
    cout<<(min(k1,k2)+(max(k1,k2)-min(k1,k2)>>1)>=w&&min(n-k1,n-k2)+(max(n-k1,n-k2)-min(n-k1,n-k2)>>1)>=b?"yEs\n":"nO\n");
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}