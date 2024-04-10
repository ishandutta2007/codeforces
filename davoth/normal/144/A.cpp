#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b, b+n);
    int ni,in,cnt=0;
    for(int i=0; i<n; i++){
        if(a[i]==b[n-1]){
            ni=i;
            cnt+=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(a[i]==b[0]){
            in=i;
            cnt+=n-1-i;
            break;
        }
    }
    if(ni>in) cnt--;
    cout << cnt;
    return 0;
}