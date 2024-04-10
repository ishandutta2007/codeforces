#include <bits/stdc++.h>
using namespace std;

int n;
int ans1,ans2;

int main(){
    cin>>n;
    for (int i=1;i<n;++i) {
        int x=i;
        int y=n-i;
        if (x>=y) continue;
        if (__gcd(x,y)==1) {
            ans1=x;
            ans2=y;
        }
    }
    cout<<ans1<<" "<<ans2;
}