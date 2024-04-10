#include <iostream>
using namespace std;

int n;
int ans[7];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<7; j++){
            char c; cin >> c;
            ans[j] += c-'0';
        }
    }
    int k=0;
    for(int i=0; i<7; i++) k=max(k,ans[i]);
    cout << k << '\n';
    return 0;
}