#include <iostream>
using namespace std;
int main(){
    int n, sum=0, t, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> t;
        sum += t;
    }
    ++n;
    for(int i = 1; i <= 5; ++i)
        if((sum + i)%n!=1) ++ans;
    cout << ans << endl;
    return 0;
}