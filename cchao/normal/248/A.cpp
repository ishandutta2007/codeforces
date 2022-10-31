#include <iostream>
using namespace std;
int main(){
    int n, l[2] = {0}, r[2] = {0};
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        l[a]++, r[b]++;
    }
    cout << min(l[0], l[1]) + min (r[0], r[1]) << endl;
    return 0;
}