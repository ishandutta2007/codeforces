#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000001];
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        long long x=i;
        if (x<k) k-=x;
        else {
            cout<<a[k];
            return 0;
        }
    }
}