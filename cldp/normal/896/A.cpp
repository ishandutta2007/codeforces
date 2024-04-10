#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const long long LINF = 1LL * 1000000000 * 1000000000 + 9;
const double PI = acos(-1.0);
const string S = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string Q = "What are you doing while sending ? Are you busy? Will you send ?";
const string S1 = "What are you doing while sending \"";
const string S2 = "\"? Are you busy? Will you send \"";
const string S3 = "\"?";


long long f[MAXN];

char cal(long long pos, int i) {
    if (i == 0) return S[pos];

    if (pos < S1.size()) return S1[pos];
    pos -= S1.size();
    if (pos < f[i - 1]) return cal(pos, i - 1);
    pos -= f[i - 1];
    if (pos < S2.size()) return S2[pos];
    pos -= S2.size();
    if (pos < f[i - 1]) return cal(pos, i - 1);
    pos -= f[i - 1];
    return S3[pos];
}

int main() {
    ios_base::sync_with_stdio(false);
    f[0] = S.size();
    for (int i = 1; i <= 100000; ++i) {
        f[i] = f[i - 1] * 2 + S1.size() + S2.size() + S3.size();
        if (f[i] > LINF) f[i] = LINF;
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        long long b;
        cin >> a >> b;
        if (f[a] < b) {
            cout << ".";
            continue;
        }
        cout << cal(b - 1, a);
    }
    cout << endl;
    return 0;
}