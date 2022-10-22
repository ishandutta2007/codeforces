#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    vector <int> vec;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n * 2; i++){
        if (a[i % n] == 0){
            vec.push_back(ans);
            ans = 0;
        }else{
            ans++;
        }
    }
    vec.push_back(ans);
    sort (vec.rbegin(), vec.rend());
    cout << vec[0];
}