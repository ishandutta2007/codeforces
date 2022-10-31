#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b, arr[2005];

int main() {
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    sort(arr, arr+n);
    if(arr[b-1] == arr[b])
        cout << "0\n";
    else
        cout << arr[b] - arr[b-1] << "\n";
    return 0;
}