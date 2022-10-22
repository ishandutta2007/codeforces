#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long a[n*2];
    if(n%2==0){
        cout << "NO";
        return 0;
    }
    int co=0;
    for(long long i=1; i<=n; i++){
        if(co==0){
            a[i-1]=i*2-1;
            a[i+n-1]=i*2;
            co=1;
        }else{
            a[i-1]=i*2;
            a[i-1+n]=i*2-1;
            co=0;
        }
    }
    cout << "YES\n";
    for(long long i=0; i<n*2; i++) cout << a[i] << ' ';
    return 0;
}