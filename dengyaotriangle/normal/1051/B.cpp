#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    unsigned long long l,r;
    cin>>l>>r;
    cout<<"YES\n";
    for(unsigned long long i=l;i<=r;i+=2)cout<<i<<' '<<i+1<<'\n';
    return 0;
}