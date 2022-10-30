#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n<4) {
        cout<<"NO";
        return 0;
    }
    if (n==5) {
        cout<<"YES"<<'\n';
        cout<<"3 - 1 = 2"<<'\n';
        cout<<"5 - 2 = 3"<<'\n';
        cout<<"2 * 3 = 6"<<'\n';
        cout<<"6 * 4 = 24";
        return 0;
    }
    cout<<"YES"<<'\n';
    cout<<"2 * 3 = 6"<<'\n';
    cout<<"6 * 4 = 24"<<'\n';
    if (n==4) {
        cout<<"1 * 24 = 24";
        return 0;
    }
    cout<<"6 - 5 = 1"<<'\n';
    cout<<"1 - 1 = 0"<<'\n';
    for (int i=7;i<=n;++i)
        cout<<i<<" * 0 = 0"<<'\n';
    cout<<"24 + 0 = 24"<<'\n';
    return 0;
}