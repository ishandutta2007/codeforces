#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    if (n%2==1) cout<<"-1";
    else {
        for (int i=1;i<=n/2;++i)
            cout<<i*2<<" "<<i*2-1<<" ";
    }
}