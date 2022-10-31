#include <bits/stdc++.h>
using namespace std;

int n,pos,l,r;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>pos>>l>>r;
    if (l==1 && r==n) {
        cout<<"0";
        return 0;
    }
    if (l==1) {
        cout<<abs(pos-(r))+1;
        return 0;
    }
    if (r==n) {
        cout<<abs(pos-l)+1;
        return 0;
    }
    int ans=abs(pos-l)+1+abs(r-l)+1;
    ans=min(ans,abs(pos-r)+1+abs(r-l)+1);
    cout<<ans;
}