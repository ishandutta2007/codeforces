#include <bits/stdc++.h>
using namespace std;
long long n,m,last;

int main(){
    cin>>n>>m;
    last=1;
    for (int i=1;i<=n;++i){
        long long k=last*2;
        if ((m-last)%k==0){
            cout<<i;
            return 0;
        }
        last*=2;
    }
}