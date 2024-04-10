#include <bits/stdc++.h>
using namespace std;

int n,ans;

int main(){
    cin>>n;
    while (n) {
        int x=n;
        int mx=0;
        while (x) {
            mx=max(mx,x%10);
            x/=10;
        }
        n-=mx;
        ++ans;
    }
    cout<<ans;
}