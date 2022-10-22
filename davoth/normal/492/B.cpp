#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l;
    cin >> n >> l;
    int la[n];
    for(int i=0; i<n; i++){
        cin >> la[i];
    }
    sort(la,la+n);
    double mxd=la[0];
    for(int i=0; i<n-1; i++){
        if((la[i+1]-la[i])/2.0>mxd){
            mxd=(la[i+1]-la[i])/2.0;
        }
    }
    if(l-la[n-1]>mxd) mxd=l-la[n-1];
    cout << fixed << setprecision(10) << mxd;
    return 0;
}