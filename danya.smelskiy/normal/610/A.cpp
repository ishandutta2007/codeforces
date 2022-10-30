#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int main(){
    cin>>n;
    if (n%2==1) {
        cout<<"0";
        return 0;
    }
    ans=n/4;
    if (n%4==0) --ans;
    cout<<ans;
}