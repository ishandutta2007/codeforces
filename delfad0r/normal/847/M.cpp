#include <iostream>
using namespace std;

int n;
int a[120];

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    int d = a[1]-a[0];
    for(int i=2; i<n; i++){
        if(a[i]-a[i-1]!=d){
            cout << a[n-1] << '\n';
            return 0;
        }
    }
    cout << a[n-1] + d << '\n';
    return 0;
}