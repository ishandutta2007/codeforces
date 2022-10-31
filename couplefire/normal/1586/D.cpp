#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, nxt[N], arr[N], start;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cout << "? ";
        for(int j = 1; j<=n; ++j)
            cout << (j==i?'2':'1') << ' ';
        cout << endl;
        int res; cin >> res;
        if(res && res<i) nxt[i] = res;
    }
    for(int i = 1; i<=n; ++i){
        cout << "? ";
        for(int j = 1; j<=n; ++j)
            cout << (j==i?'1':'2') << ' ';
        cout << endl;
        int res; cin >> res;
        if(!res) start = i;
        else if(res<i) nxt[res] = i;
    }
    for(int i = 1, id = start; i<=n; ++i, id = nxt[id])
        arr[id] = i;
    cout << "! ";
    for(int i = 1; i<=n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}