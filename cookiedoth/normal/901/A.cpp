#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 200000;
int h, a[mx], t1[mx], t2[mx];

int main()
{
    cin >> h;
    h++;
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    int pos = -1;
    for (int i = 0; i < h - 1; ++i) {
        if (a[i] > 1 && a[i + 1] > 1) {
            pos = i;
        }
    }
    if (pos == -1) {
        cout << "perfect" << endl;
        return 0;
    }
    t1[0] = -1;
    t2[0] = -1;
    int v = 0;
    for (int i = 1; i < h; ++i) {
        if (i != pos + 1) {
            for (int j = 0; j < a[i]; ++j) {
                t1[v + 1 + j] = v;
                t2[v + 1 + j] = v;
            }
        }
        else {
            t1[v + 1] = v - 1;
            t2[v + 1] = v;
            for (int j = 1; j < a[i]; ++j) {
                t1[v + 1 + j] = v;
                t2[v + 1 + j] = v;
            }
        }
        v += a[i];
    }
    cout << "ambiguous" << endl;
    for (int i = 0; i <= v; ++i) {
        cout << t1[i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i <= v; ++i) {
        cout << t2[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}