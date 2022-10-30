#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (360%(180-x)==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}