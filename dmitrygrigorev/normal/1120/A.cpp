#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 500007;
vector<vector<int> > arr(K);
int numbers[K+1];
int where[K+1], need[K+1];
int n;
int bs(int element, int number, int start){
    int L = -1, R = arr[element].size();
    while (R-L>1){
        int M = (L+R)/2;
        if (arr[element][M] >= start) R = M;
        else L = M;
    }
    if (arr[element].size() - R < number) return n;
    return arr[element][R+number-1];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m;
    cin >> n >> k >> m;
    int value;
    cin >> value;
    vector<int> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
        arr[v[i]-1].push_back(i);
    }
    for (int i=0; i < n; i++) v[i]--;
    for (int i=0; i < value; i++){
        int T;
        cin >>T;
        need[T-1]++;
    }
    for (int i=0; i < K; i++) if (need[i]){
        numbers[n]++;
        where[i] = n;
    }
    int mx = n;
    for (int i=n-1; i >= 0; i--){
        int element = v[i];
        //if (need[element] == 0) continue;
        int old, index;
        if (need[element]){
            old = where[element];
            index = bs(element, need[element], i);
        }
        else{
            old = 0, index=0;
        }
        //cout << i << " " << old << " " << index << endl;
        numbers[old]--;
        numbers[index]++;
        //cout << numbers[mx] << endl;
        where[element] = index;
        while (numbers[mx] == 0) mx--;
        //cout << i << " "  << " " << index << " " << need[element] << endl;
        int can = (i/k)*k + min(mx-i+1, k) + (n-1-mx);
        //cout << i << " " << can << " " << mx << endl;
        if (can < m*k || mx==n) continue;
        vector<int> dlt;
        for (int j=(i/k)*k; j < i; j++) dlt.push_back(j);
        int mst = max((int) 0, mx-i+1-min(mx-i+1,k));
        for (int j=i; j <= mx; j++){
            int element = v[j];
            if (need[element] > 0) need[element]--;
            else{
                if (mst > 0) dlt.push_back(j);
                mst--;
            }
        }
        cout << dlt.size() << endl;
        for (int j=0; j < dlt.size();j++) cout << dlt[j]+1 << " ";
        return 0;
    }
    cout << -1;



}