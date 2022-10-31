#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int main(){
    cin>>n>>m>>k;
    if (n%2==0) cout<<"Marsel";
    else {
        for (int i=2;i<=sqrt(m);++i)
        if (m%i==0) {
            if (i>=k || m/i>=k) {
                cout<<"Timur";
                return 0;
            }
        }
        if (k==1 && m>k) cout<<"Timur"; else
        cout<<"Marsel";
    }
}