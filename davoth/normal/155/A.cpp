#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    int l[n];
    for(int i=0; i<n; i++){
        cin >> l[i];
    }
    int ma=l[0],mi=l[0];
    for(int i=1; i<n; i++){
        if(l[i]>ma){
            cnt++;
            ma=l[i];
        }else if(l[i]<mi){
            cnt++;
            mi=l[i];
        }
    }
    cout << cnt;
    return 0;
}