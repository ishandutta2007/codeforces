#include <bits/stdc++.h>
using namespace std;

bool dbg =0;
vector<int> tmp = {1, 6, 4, 2, 3, 5, 4};

int ask(string s, int i, int j){
    cout << s << ' ' << i+1 << ' ' << j+1 << endl;
    if(dbg){
        if(s=="and") return tmp[i]&tmp[j];
        else return tmp[i]|tmp[j];
    }
    int res; cin >> res;
    return res;
}

int main(){
    // freopen("a.in", "r", stdin);
    int n, k; cin >> n >> k;
    vector<int> arr(n), brr(n), a(n), o(n);
    for(int i = 1; i<n; ++i){
        int v1 = ask("and", 0, i), v2 = ask("or", 0, i);
        a[i] = v1, o[i] = v2;
        brr[i] = (v1^v2);
    }
    arr[0] = (((o[1]|o[2])&((a[1]&a[2])|((1<<30)-1-(a[1]^a[2]^ask("and", 1, 2)))))^brr[1]^brr[2]);
    for(int i = 1; i<n; ++i)
        arr[i] = arr[0]^brr[i];
    sort(arr.begin(), arr.end());
    cout << "finish" << ' ' << arr[k-1] << endl;
}