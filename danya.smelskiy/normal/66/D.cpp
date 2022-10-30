#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==2) {
        cout<<"-1";
        return 0;
    }
    cout<<"10\n6\n15\n";
    for (int i=4;i<=n;++i)
        cout<<15*i<<"\n";
}