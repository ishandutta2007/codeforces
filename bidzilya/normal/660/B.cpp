#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

pair<int, int> GetSeatPos(int n, int num) {
    if (num >= 2 * n) {
        pair<int, int> seatPos = GetSeatPos(n, num - 2 * n);
        if (seatPos.second == 0) {
            ++seatPos.second;
        } else {
            --seatPos.second;
        }
        return seatPos;
    } else {
        if (num & 1) {
            return make_pair(num >> 1, 3);
        } else {
            return make_pair(num >> 1, 0);
        }
    }
}

pair<int, int> GetOutPos(int n, int num) {
    int i = num / 4;
    int j;
    switch (num % 4) {
        case 0:
            j = 1;
            break;
        case 1:
            j = 0;
            break;
        case 2:
            j = 2;
            break;
        case 3:
            j = 3;
            break;
    }
    return make_pair(i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(4, -1));
    for (int i = 0; i < m; ++i) {
        pair<int, int> seatPos = GetSeatPos(n, i);

        a[seatPos.first][seatPos.second] = i;
    }

    for (int i = 0; i < 4 * n; ++i) {
        pair<int, int> outPos = GetOutPos(n, i);

        int x = a[outPos.first][outPos.second];
        if (x != -1) {
            cout << x + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}