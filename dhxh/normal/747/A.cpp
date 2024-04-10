#include <iostream>
#include <cmath>

using namespace std;

int n;
int h;
int ans;

int main() {
    int i, j;
    
    cin >> n;
    
    h = sqrt(n);
    
    for(i=1;i<=h;i++){
        if(n % i == 0){
            ans = i;
        }
    }
    
    cout << ans << " " << n / ans << endl;
    
    
    return 0;
}