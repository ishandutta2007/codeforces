#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
long long k;
int main(){
    cin>>a>>b>>c;
    for(int i=1;i<=c;++i){
        k+=i*a;
    }
    if (k-b<0) cout<<"0";
    else cout<<k-b;
}