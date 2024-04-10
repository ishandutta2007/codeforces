#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n]={0};
    int p,q;
    cin >> p;
    for(int i=0; i<p; i++){
        int temp;
        cin >> temp;
        a[temp-1]=1;
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int temp;
        cin >> temp;
        a[temp-1]=1;
    }
    for(int i=0; i<n; i++){
        if(!a[i]){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
    return 0;
}