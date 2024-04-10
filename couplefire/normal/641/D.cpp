#include <bits/stdc++.h>
using namespace std;

pair<double, double> quadratic(double sum, double prod){
    return {(sum+sqrt(max(sum*sum-4*prod, 0.0)))/2, (sum-sqrt(max(sum*sum-4*prod, 0.0)))/2};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    if(n == 1){
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    double arr1[n], arr2[n];
    double sum1[n], sum2[n];
    for(int i = 0; i<n; i++) cin >> arr1[i];
    for(int i = 0; i<n; i++) cin >> arr2[i];
    sum1[0] = arr1[0];
    for(int i = 1; i<n; i++) sum1[i] = sum1[i-1]+arr1[i];
    sum2[n-1] = arr2[n-1];
    for(int i = n-2; i>=0; i--) sum2[i] = sum2[i+1]+arr2[i];
    double ans1[n], ans2[n];
    double prev1 = 0, prev2 = 0;
    for(int i = 0; i<n-1; i++){
        ans1[i] = quadratic(sum1[i]-sum2[i+1]+1, sum1[i]).first;
        ans2[i] = quadratic(sum1[i]-sum2[i+1]+1, sum1[i]).second;
    }
    ans1[n-1] = ans2[n-1] = 1;
    for(int i = 0; i<n; i++){
        cout << ans1[i]-prev1 << " ";
        prev1 = ans1[i];
    }
    cout << endl;
    for(int i = 0; i<n; i++){
        cout << ans2[i]-prev2 << " ";
        prev2 = ans2[i];
    }
    cout << endl;
}