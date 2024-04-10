#include<bits/stdc++.h>

using namespace std;

long long s,a,b,c;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>s>>a>>b>>c;
        s/=c;
        long long m=s/a;
        cout<<m*(a+b)+(s-m*a)<<endl;

    }
    return 0;
}