#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    long long brr[n];
    long long crr[n];
    for(int i = 0; i<n; i++) cin >> brr[i];
    for(int i = 0; i<n; i++) cin >> crr[i];
    long long sum = 0;
    for(int i = 0; i<n; i++) sum += brr[i], sum += crr[i];
    if(sum%(2*n) != 0){
        cout << -1 << endl;
        exit(0);
    }
    sum /= 2*n;
    long long arr[n];
    for(int i = 0; i<n; i++){
        if((0ll+brr[i]+crr[i]-sum)%n != 0){
            cout << -1 << endl;
            exit(0);
        }
        arr[i] = (0ll+brr[i]+crr[i]-sum)/n;
        if(arr[i] < 0){
            cout << -1 << endl;
            exit(0);
        }
    }
    int bits[32];
    fill(bits, bits+32, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<32; j++){
            if(arr[i]&(1<<j)) bits[j]++;
        }
    }
    for(int i = 0; i<n; i++){
        long long tb = 0;
        for(int j = 0; j<32; j++){
            if(arr[i]&(1<<j)) tb += 1ll*(1<<j)*bits[j];
        }
        if(tb != brr[i]){
            cout << -1 << endl;
            exit(0);
        }
    }
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}