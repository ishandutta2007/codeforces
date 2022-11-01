#include<bits/stdc++.h>
using namespace std;

void mian(){
    long long n,k,c=1,t=0;
    cin>>n>>k;
    while(c<k){
        t++;
        c*=2;
    }
    if(c>=n)cout<<t<<'\n';
    else cout<<(n-c+k-1)/k+t<<'\n';
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