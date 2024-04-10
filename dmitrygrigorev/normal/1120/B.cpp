#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
void change(set<int> &can, int index, vector<int> &diff, vector<int> &A){
    if (index < 0 || index >= n-1) return;
    //cout << index << " " << diff[index] << endl;
    if (can.count(index)) can.erase(can.find(index));
    if (diff[index] == 0) return;
    //cout << diff[index] << " " << A[index] << " " << A[index+1] << endl;
    if (diff[index] > 0 && A[index] != 9 && A[index+1] != 9) can.insert(index);
    if (diff[index] < 0 && A[index] != 0 && A[index+1] != 0) can.insert(index);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> diff(n-1);
    vector<int> A(n), B(n);
    for (int i=0; i < n; i++) A[i] = a[i] - '0';
    for (int i=0; i < n; i++) B[i] = b[i] - '0';
    int moves=0;
    vector<int> C = A;
    for (int i=0; i < a.size()-1; i++){
        int D = B[i] - A[i];
        diff[i]=D;
        A[i+1] += D;
        moves += abs(D);
    }
    if (A[n-1] != B[n-1]){
        cout << -1;
        return 0;
    }
    cout << moves << endl;
    set<int> can;
    for (int i=0; i < n-1; i++){
        change(can, i, diff, C);
    }
    //cout << can.size() << endl;
    for (int i=0; i < min((int) 100000, moves); i++){
        if (!can.size()){
            cout << -1;
            return 0;
        }
        int index = *(can.begin());
        if (diff[index] > 0){
            cout << index+1 << " " << 1 << endl;
            C[index]++, C[index+1]++, diff[index]--;
        }
        else{
            cout << index +1<< " " << -1 << endl;
            C[index]--, C[index+1]--, diff[index]++;
        }
        change(can, index, diff, C);
        change(can, index-1, diff, C);
        change(can, index+1, diff, C);
    }
}