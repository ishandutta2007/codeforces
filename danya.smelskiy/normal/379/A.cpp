#include <bits/stdc++.h>
using namespace std;
int a,b,k,ans;
int main(){
    cin>>a>>b;
    while (a>0){
        --a;
        ++ans;
        ++k;
        if (k==b){ k=0; ++a;}
    }
    cout<<ans;
}