#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int H[n];
    string aa;
    cin >> aa;
    int Dd[n];
    int De[n];
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        if (aa[i] == '0') {
            H[cc] = i;
            cc++;
            Dd[i] = De[i] = 0;
        }
        else Dd[i] = De[i] = 1e6;
    }
    int ant = 1e6;
    for (int i = 0; i < n; ++i) {
        Dd[i] = min(Dd[i], ant + 1);
        ant = Dd[i];
//         cerr << Dd[i] << ' ';
    }
//     cerr << endl;
    ant = 1e6;
    for (int i = n - 1; i >= 0; --i) {
        De[i] = min(De[i], ant + 1);
        ant = De[i];
    }
//     for (int i = 0; i < n; ++i) cerr <<De[i] << ' ';
//     cerr << endl;
    int a = H[0];
    int b = H[k];
    
    int res = 1e6;
    
    for (int i = k; i < cc; ++i) {
        a = H[i - k];
        b = H[i];
        int c1 = (a + b)/2;
        int c2 = (a + b + 1)/2;
        int dd1 = min(Dd[c1] + b - c1, De[c1] + c1 - a);
        int dd2 = min(Dd[c2] + b - c2, De[c2] + c2 - a);
        res = min(res, max(min(dd1, dd2), (b - a + 1)/2));
    }
    cout << res << endl;
}