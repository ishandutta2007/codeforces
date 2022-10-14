#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int run(vector<int>& A, vector<int>& B) {
    int N = A.size(), M = B.size();
    A.push_back(INT_MAX - 300'000);
    B.push_back(INT_MAX - 300'000);

    vector<int> Btail(M, 1);
    for (int i = M - 1, j = M - 1; i >= 0; i--) {
        while (i <= j && B[j] - B[i] > i)
            j--;
        Btail[i] = j - i + 1;
    }
    int score = 0;
    for (int a = 0, b = 0; a < N && b < M;) {
        if (A[a] == B[b]) {
            score++, a++, b++;
        } else if (A[a] < B[b]) {
            a++;
        } else {
            b++;
        }
    }
    int wagon = 0, i = 0, bl = 0, ar = 0, br = 0;
    int ans = score;

    while (ar < N && i + wagon == A[ar]) {
        br += i + wagon == B[br], wagon++, ar++;
    } // attach new blocks to the end of the wagon

    while (bl < M) {
        int adv_bl = bl == M ? INT_MAX : B[bl] - i;
        int adv_br = br == M ? INT_MAX : B[br] - (i + wagon) + 1;
        int adv_ar = ar == N ? INT_MAX : A[ar] - (i + wagon);
        int adv = min(adv_bl, min(adv_ar, adv_br));
        // printf("%d(+%d) [%d] {%d} %d %d %d\n", i, adv, wagon, score, B[bl], B[br],
        // A[ar]);
        assert(adv > 0);
        i += adv;
        score += br < M && adv == adv_br && wagon;
        br += br < M && adv == adv_br;
        while (ar < N && i + wagon == A[ar]) {
            br += i + wagon == B[br], wagon++, ar++;
        } // attach new blocks to the end of the wagon
        ans = max(ans, score);
        score -= i == B[bl] && wagon;
        bl += i == B[bl];
    }
    // printf("score: %d\n", score);
    assert(score == 0);
    return ans;
}

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int j = 0; j < M; j++)
        cin >> B[j];
    int azero = lower_bound(begin(A), end(A), 0) - begin(A);
    int bzero = lower_bound(begin(B), end(B), 0) - begin(B);
    vector<int> Aright(begin(A) + azero, end(A));
    vector<int> Bright(begin(B) + bzero, end(B));
    vector<int> Aleft(begin(A), begin(A) + azero);
    vector<int> Bleft(begin(B), begin(B) + bzero);
    reverse(begin(Aleft), end(Aleft));
    reverse(begin(Bleft), end(Bleft));
    for (int& a : Aleft)
        a = -a;
    for (int& b : Bleft)
        b = -b;
    return run(Aright, Bright) + run(Aleft, Bleft);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    setbuf(stdout, nullptr);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}