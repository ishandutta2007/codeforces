#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n%2==0) {
        if (n==2) cout<<"aa";
        else {
            for (int i=1;i<=n/4;++i)
                cout<<"aabb";
            if (n%4==2) cout<<"aa";
        }
    } else {
        for (int i=1;i<=n/4;++i)
            cout<<"aabb";
        if (n%4==1) cout<<"a";
        else cout<<"aab";
    }
}