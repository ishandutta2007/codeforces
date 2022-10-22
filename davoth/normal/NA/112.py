#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,p=1;
    long long r=0;
    cin >> n >> m;
    int t[m];
    for(int i=0; i<m; i++){
        cin >> t[i];
    }
    for(int i=0; i<m; i++){
        if(t[i]>p){
            r+=t[i]-p;
            p=t[i];
        }else if(t[i]<p){
            r+=n-p+t[i];
            p=t[i];
        }
    }
    cout << r;
    return 0;
}