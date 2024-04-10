#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main() {
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    int d=-1;
    for(int i=0; i<n; i++){
        if(d<=a[i].second){
            d=a[i].second;
        }else d=a[i].first;
    }
    cout << d;
    return 0;
}