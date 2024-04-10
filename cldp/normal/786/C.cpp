#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 101000;

int N, c[MAXN];
int ocr[MAXN], nxtocr[MAXN];
int cnt[MAXN], a[MAXN];
vector<int> r[MAXN];


void modify(int x,int s) {
    for (int i = x; x <= N + 1; x += x & (-x)) c[x] += s;
}

int find(int x) {
    int p = 0;
    for (int i = 19; i >= 0; --i) {
        if (p + (1 << i) <= N + 1 && c[p + (1 << i)] < x) {
            x -= c[p + (1 << i)];
            p += (1 << i);
        }
    }
    return p + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        ocr[i] = N + 1;
    }
    for (int i = N; i >= 1; --i) {
        nxtocr[i] = ocr[a[i]];
        ocr[a[i]] = i;
    }
    /*
    for (int i = 1; i <= N; ++i) cout << ocr[i] << " ";
    cout << endl;
    for (int i = 1; i <= N; ++i) cout << nxtocr[i] << " ";
    cout << endl;
*/
    for (int i = 1; i <= N; ++i) {
        modify(ocr[i], 1);
        r[1].push_back(i);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            int k = find(r[i][j] + 1);
            ++cnt[r[i][j]];
            r[k].push_back(r[i][j]);
        }
        modify(i, -1);
        modify(nxtocr[i], 1);
    }
    for (int i = 1; i <= N; ++i) cout << cnt[i] << " ";
    cout << endl;
}