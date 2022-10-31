#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n%2==0) {
        while (n) {
            cout<<"1";
            n-=2;
        }
        return 0;
    }
    cout<<7;
    n-=3;
    while (n) {
        cout<<"1";
        n-=2;
    }
}