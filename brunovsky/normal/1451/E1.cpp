#include <bits/stdc++.h>

using namespace std;

#define long int64_t

int QUERY(string op, int i, int j) {
    printf("%s %d %d\n", op.data(), i, j);
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    setbuf(stdout, nullptr);
    int N;
    cin >> N;

    vector<int> arr(N + 1);
    for (int i = 2; i <= N; i++) {
        arr[i] = QUERY("XOR", 1, i);
    }

    auto print = [&]() {
        string s = "!";
        for (int i = 1; i <= N; i++) {
            s += " " + to_string(arr[i]);
        }
        printf("%s\n", s.data());
        exit(0);
    };

    int zero = -1;
    for (int i = 2; i <= N; i++) {
        if (arr[i] == 0) {
            zero = i;
            break;
        }
    }
    if (zero >= 2) {
        arr[1] = QUERY("OR", 1, zero);
        for (int i = 2; i <= N; i++) {
            arr[i] = arr[1] ^ arr[i];
        }
        print();
    }

    vector<vector<int>> by_val(N);
    for (int i = 2; i <= N; i++) {
        by_val[arr[i]].push_back(i);
    }
    assert(by_val[0].empty());

    int repeat = -1;
    for (int v = 1; v < N; v++) {
        if (by_val[v].size() > 1u) {
            repeat = v;
            break;
        }
    }
    if (repeat >= 1) {
        int a = by_val[repeat][0];
        int b = by_val[repeat][1];
        int x = QUERY("OR", a, b);
        arr[1] = x ^ arr[a];
        for (int i = 2; i <= N; i++) {
            arr[i] = arr[1] ^ arr[i];
        }
        print();
    }

    int a = -1, b = -1;
    for (int i = 2; i <= N; i++) {
        if (arr[i] == 1) {
            a = i;
        } else if (arr[i] == N - 2) {
            b = i;
        }
    }

    assert(a >= 2 && b >= 2 && a != b);
    arr[1] = QUERY("AND", 1, a) | QUERY("AND", 1, b);
    for (int i = 2; i <= N; i++) {
        arr[i] = arr[1] ^ arr[i];
    }
    print();

    return 0;
}