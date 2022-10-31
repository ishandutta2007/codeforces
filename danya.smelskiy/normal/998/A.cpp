#include <bits/stdc++.h>
using namespace std;





int n;
int pos;
int a[100];
int mn=1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]<mn) {
            mn=a[i];
            pos=i;
        }
    }
    if (n==1 || (n==2 && a[1]==a[2])) cout<<"-1";
    else cout<<"1\n"<<pos;
}