#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    int best = -1, score = 1e9;
    for(int i = 1; i < n-1; ++i) {
        if(arr[i+1] - arr[i-1] < score) {
            best = i;
            score = arr[i+1] - arr[i-1];
        }
    }
    int diff = 0;
    for(int i = 1; i < n; ++i) {
        if(i == best) {
            diff = max(diff, arr[i+1] - arr[i-1]);
            ++i;
            continue;
        }
        
        diff = max(diff, arr[i] - arr[i-1]);
    }
    cout << diff << "\n";
    
}