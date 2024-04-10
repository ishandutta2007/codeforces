#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        k+=n+n;
        int last=1;
        int x=1;
        while (k--) {
            int y=(x+last)%n;
            if (y==0) y=n;
            cout<<x<<" "<<y<<'\n';
            ++x;
            if (x==n+1) {
                x=1;
                ++last;
            }
        }
    }
}