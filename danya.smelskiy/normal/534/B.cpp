#include <bits/stdc++.h>
using namespace std;

long long v,v1,t,d;
long long ans;
int main(){
    cin>>v>>v1;
    cin>>t>>d;
    for (int i=0;i<t;++i){
        long long x=min(v+i*d,v1+(t-i-1)*d);
        ans+=x;
    }
    cout<<ans;
}