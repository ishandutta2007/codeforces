#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,h=0;
    cin >> n;
    for(int i=1; ; i++){
        if(i*(i+1)/2>n) break;
        else{
            n-=i*(i+1)/2;
            h++;
        }
    }
    cout << h;
    return 0;
}