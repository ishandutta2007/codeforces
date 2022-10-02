#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if(a == c) ans += 2;
    if(b == d) ans += 2;
    ans += 2*abs(a-c) + 2*abs(b-d) + 4;
    cout << ans << '\n';
}