#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int r=0;
    int p=0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp!=p){
            r++;
            p=temp;
        }
    }
    cout << r;
    return 0;
}