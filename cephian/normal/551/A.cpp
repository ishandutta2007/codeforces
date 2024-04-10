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
    int freq[2001];
    fill(freq, freq+2001, 0);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0; i < n;++i)
        ++freq[arr[i]];
    int amt = 1;
    for(int i = 2000; i >= 0; --i){
        amt += freq[i];
        freq[i] = amt - freq[i];
    }
    for(int i = 0; i < n;++i)
        cout << freq[arr[i]] << ((i == n-1)?"\n":" ");
}