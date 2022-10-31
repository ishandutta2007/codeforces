#include <bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
    cin>>n>>k;
    long long z=4*60;
    z-=k;
    if (z<=0) cout<<0;
    else {
        long long last=0;
        for (int i=1;i<=n;++i){
            if (last+i*5>z){
                cout<<i-1;
                return 0;
            } else last+=i*5;
        }
    cout<<n<<endl;
    }
}