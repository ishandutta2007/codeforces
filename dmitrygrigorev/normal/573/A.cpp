#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int x = -1;
    for (int i=0; i < n; i++){
        int a; cin >> a;
        while (a % 2 == 0) a/=2;
        while (a%3==0) a/=3;
        if (x!=-1 && a !=x){
            cout << "No" << endl;
            return 0;
        }
        x = a;
    }
    cout << "Yes" << endl;
    return 0;
}