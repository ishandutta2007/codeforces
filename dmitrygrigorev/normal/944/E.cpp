#include <bits/stdc++.h>
using namespace std;
int bin(vector<int> &v, int num){
    int L = 0, R = v.size() + 1;
    while (R-L > 1){
        int M = (L+R) / 2;
        if (v[M-1] <= num) L = M;
        else R = M;
    }
    return L;
}
signed main()
{
    //freopen("1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int bal[m+1];
    for (int i=0; i <= m; i++) bal[i] = 0;
    for (int i=0; i < n; i++){
        int l, r;
        cin >> l >> r;
        bal[l-1]++;
        bal[r]--;
    }
    int how[m];
    for (int i=0; i < m; i++) how[i] = 0;
    int N = 0;
    for (int i=0; i < m; i++){
        N += bal[i];
        how[i] = N;
    }
    int nvp[m], onvp[m];
    vector<int> v;
    v.push_back(-1);
    v.push_back(how[0]);
    nvp[0] = 1;
    for (int i=1; i < m; i++){
        int pos = bin(v, how[i]);
        nvp[i] = pos;
        //cout << nvp[i] << "!" << endl;
        if (pos==v.size()){
            v.push_back(how[i]);
        }
        else v[pos] = how[i];
    }
    v.clear();
    v.push_back(-1);
    v.push_back(how[m-1]);
    onvp[m-1] = 1;
    for (int i=m-2; i >= 0; i--){
        int pos = bin(v, how[i]);
        onvp[i] = pos;
        if (pos==v.size()){
            v.push_back(how[i]);
        }
        else v[pos] = how[i];
    }
    int A = 0;
    for (int i=0; i < m; i++){
        A = max(A, nvp[i] + onvp[i] - 1);
    }
    cout << A << endl;
    return 0;
}