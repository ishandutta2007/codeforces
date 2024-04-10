#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int l=1;
    int r=n;
    int last=1;
    while (l!=r) {
        if (last==l) {
            ans+=(last+r)%(n+1);
            last=r;
            ++l;
        } else {
            ans+=(last+l)%(1+n);
            last=l;
            --r;
        }
    }
    cout<<ans;
}