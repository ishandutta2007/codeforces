#include <bits/stdc++.h>
using namespace std;
long long a,b,ans;
int main(){
    cin>>a>>b;
    while (a>0 && b>0){
        if (a>b){
            ans+=a/b;
            a%=b;
        }
        else {
            ans+=b/a;
            b%=a;
        }
    }
    cout<<ans;
}