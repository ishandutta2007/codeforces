#include <iostream>

using namespace std;

const int N=2e5+10;

int n,a[N],mx=0,mn=1e9,x=0,y=0;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]>mx){
            mx=a[i];
            x=1;
        }else if(a[i]==mx) x++;
        if(a[i]<mn){
            mn=a[i];
            y=1;
        }else if(a[i]==mn) y++;
    }
    cout << mx-mn << ' ';
    if(mx==mn) cout << 1ll*n*(n-1)/2 << '\n';
    else cout << 1ll*x*y << '\n';
    return 0;
}