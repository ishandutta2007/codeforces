#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,r=0;
    cin >> n;
    int n1=n;
    int a[n];
    while(n--){
        cin >> a[n];
    }
    cin >> m;
    int m1=m;
    int b[m];
    while(m--){
        cin >> b[m];
    }
    sort(a,a+n1);
    sort(b,b+m1);
    for(int i=0; i<n1; i++){
        for(int j=0; j<m1; j++){
            if(abs(a[i]-b[j])<=1){
                r++;
                b[j]=102;
                break;
            }
        }
    }
    cout << r;
    return 0;
}