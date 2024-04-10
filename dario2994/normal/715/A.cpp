// TODO: REMOVE IO from file
#include <bits/stdc++.h>
using namespace std;

long long int N;

int main() {
    // std::ifstream cin("input.txt");
    // ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin >> N;
    cout << 2 << "\n";
    // int ris = 2;
    for (long long int k = 2; k <= N; k++) {
        // cout << k << ": " << ris << "\n";
        cout << k*(k+1)*(k+1) - (k-1) << "\n";
        // ris += (k*(k+1)*(k+1) - (k-1))*k;
        // ris = sqrt(ris);
    }
    // cout << N;
}