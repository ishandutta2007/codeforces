#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long a[n];
    int con=0;
    for(long long i=0; i<n; i++) cin >> a[i];
    long long pr=1,co=0;
    for(long long i=0; i<n; i++){
        if(a[i]<0){
            co+=-1*a[i]-1;
            pr*=-1;
        }else if(a[i]==0){
            co++;
            con=1;
        }
        else co+=a[i]-1;
    }
    if(pr==-1 && con==0) co+=2;
    cout << co;
    return 0;
}