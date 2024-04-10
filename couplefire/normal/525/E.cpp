#include <bits/stdtr1c++.h>
 
using namespace std;
 
long long s, z, f[19];
int i, n, m, k, ar[25];
unordered_map <long long, int> h[27];
 
void F(int i, int l, int r, long long x, int g){
    if (r > k || x > s) return;
    if (i == l){
        if (g) h[r][x]++;
        else{
            for (i = 0; (i + r) <= k; i++) z += h[i][s - x];
        }
        return;
    }
 
    F(i + 1, l, r, x, g), F(i + 1, l, r, x + ar[i], g);
    if (ar[i] < 19) F(i + 1, l, r + 1, x + f[ar[i]], g);
}
 
int main(){
    f[0] = 1;
    for (i = 1; i < 19; i++) f[i] = (f[i - 1] * i);
 
    cin >> n >> k >> s;
    for (i = 0; i < n; i++) cin >> ar[i];
    z = 0, m = n >> 1;
    F(0, m, 0, 0, 1), F(m, n, 0, 0, 0);
    cout << z << endl;
    return 0;
}