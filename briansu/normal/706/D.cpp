#include <bits/stdc++.h>
using namespace std;

const int MAXn = 31 * 200000 + 5;

int nxt[MAXn][2], cnt[MAXn], counter; // counter starts from 0, which is also the root

int newNode() {
    nxt[counter][0] = nxt[counter][1] = cnt[counter] = 0;
    return counter++; // return counter, counter += 1;
}

int root;
void ins(int x, int type) { // type = -1 or 1
    int level = 29, cur = root;
    while (level >= 0) {
        int t = (x>>level)&1;
        if (!nxt[cur][t])
            nxt[cur][t] = newNode();
        cur = nxt[cur][t];
        cnt[cur] += type;
        level--;
    }
}

int findY(int x) {
    int level = 29, cur = root, Y = 0;
    while (level >= 0) {
        int t = (x>>level)&1;
        if (nxt[cur][!t] && cnt[nxt[cur][!t]])
            Y += ((!t)<<level), cur = nxt[cur][!t], level--;
        else
            Y += (t<<level), cur = nxt[cur][t], level--;
    }
    return Y;
}

int main() {
    root = newNode();
    ins(0, 1);
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
            ins(x, 1);
        else if (c == '-')
            ins(x, -1);
        else
            cout << (x ^ findY(x)) << "\n";
    }
}