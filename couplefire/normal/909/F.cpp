#include <bits/stdc++.h>
using namespace std;

//7 : 7 6 1 5 3 2 4
//6 : 3 6 1 5 4 2

void solve(int n){
    if(n == 0) return;
    int largest = pow(2, floor(log2(0.0+n)));
    solve(largest-(n-largest)-2);
    for(int i = n; i>=largest-(n-largest)-1; i--) cout << i << " ";
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    if(n%2 == 1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        solve(n);
        cout << endl;
    }
    if(n < 6 || pow(2,floor(log2(0.0+n))) == n){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(n == 6){
        cout << "3 6 1 5 4 2 " << endl;
        return 0;
    }
    if(n == 7){
        cout << "7 6 1 5 3 2 4 " << endl;
        return 0;
    }
    cout << "7 6 1 5 3 2 4 ";
    int largest = (int)(pow(2,floor(log2(0.0+n))));
    int cur = 8;
    while(cur != largest){
        for(int i = cur; i<cur*2-1; i++) cout << (i+1) << " ";
        cout << cur << " ";
        cur *= 2;
    }
    for(int i = largest; i<n; i++) cout << i+1 << " ";
    cout << (int)largest << " " << endl;;
    // int n = 6;
    // int temp[n];
    // int arr[n];
    // for(int i = 0; i<n; i++){
    //     temp[i] = i+1;
    //     arr[i] = i+1;
    // }
    // do{
    //     bool lol = true;
    //     for(int i = 0; i<n; i++){
    //         if(arr[i] == temp[i] || (arr[i]&temp[i]) != 0){
    //             lol = false;
    //             break;
    //         }
    //     }
    //     if(lol){
    //         for(int i = 0; i<n; i++) cout << arr[i] << " ";
    //         cout << endl;
    //     }
    // }while(next_permutation(arr, arr+n));
}