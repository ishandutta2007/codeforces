#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<int,int> l[n];
    for(int i=0; i<n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a+=b+c+d;
        l[i].first=400-a;
        l[i].second=i+1;
    }
    sort(l,l+n);
    for(int i=0; i<n; i++){
        if(l[i].second==1){
            cout << i+1;
            break;
        }
    }
    return 0;
}