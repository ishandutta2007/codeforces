#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int L = 0, R = 1e9;
    while (R-L>1){
        int M = (L+R)/2;
        int sum = M * (M+1)/2;
        if (sum > a+b){
            R = M;
        }
        else L = M;
    }
    vector<int> A, B;
    for (int i=L; i >= 1; i--){
        if (a - i >= 0){
            A.push_back(i);
            a-=i;
        }
        else{
            B.push_back(i);
        }
    }
    cout << A.size() << endl;
    for (int i=0; i < A.size(); i++) cout << A[i] << " ";
    cout << endl;
    cout << B.size() << endl;
    for (int i=0; i < B.size(); i++) cout << B[i] << " ";
    cout << endl;
    return 0;
}