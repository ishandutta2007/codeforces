// https://codeforces.com/problemset/problem/1196/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200000

int n, k;
int arr[MAXN];
int odd[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n >> k;
    int o = 0;
    forn(i, n) cin >> arr[i];
    forn(i, n) {
        if(arr[i]%2==0) {
            odd[i] = 0;
        }
        else {
            odd[i] = 1;
            o += 1;
        }
    }
    if((k>o)||((o>k)&&((o-k)%2==1))) {
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    int skip = o-k;
    int temp = -1;
    forn(i, n) {
        if(odd[i]==1) temp += 1;
        if(temp==skip) {
            temp = i;
            break;
        }
    }
    queue <int> q;
    for(int i = temp; i<n; i++) {
        if(odd[i]==1) q.push(i+1);
    }
    while(true) {
        if(q.size()==1) {
            cout << n << endl;
            break;
        }
        cout << q.front() << " ";
        q.pop();
    }
}
    return 0;
}