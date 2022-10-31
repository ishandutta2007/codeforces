#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long arr[n];
    for(long long i = 0; i<n; i++) cin >> arr[i];
    bool black[n];
    black[0] = 1;
    for(long long i = 1; i<n; i++){
        black[i] = ((i+arr[0]-arr[i]+1)%2+2)%2;
    }
    long long numb = 0, numw = 0;
    long long sum = 0;
    for(long long i = 0; i<n; i++){
        sum += arr[i];
        if(arr[i] % 2 == 1){
            if(black[i]){
                numb += (arr[i]+1)/2;
                numw += (arr[i]-1)/2;
            }
            else{
                numb += (arr[i]-1)/2;
                numw += (arr[i]+1)/2;
            }
        }
    }
    cout << (sum-abs(numb-numw))/2 << endl;
}