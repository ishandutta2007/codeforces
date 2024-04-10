#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int F_MAX = 14;
const long long LL_INF = (long long) 1e18 + 5;

vector<string> F;

void prepare() {
    F = {"0", "1"};

    while (F.size() <= F_MAX)
        F.push_back(F[F.size() - 2] + F.back());
}

bool starts_with(int n, const string &str, int start, size_t len) {
    int index = n <= F_MAX ? n : F_MAX - n % 2;
    return len <= F[index].size() && F[index].compare(0, len, str, start, len) == 0;
}

bool ends_with(int n, const string &str, int start, size_t len) {
    int index = min(n, F_MAX);
    return len <= F[index].size() && F[index].compare(F[index].size() - len, len, str, start, len) == 0;
}

long long occurrences(int n, const string &str) {
    vector<long long> dp(n + 1);

    for (int len = 0; len <= n; len++) {
        if (len <= 1) {
            dp[len] = F[len] == str ? 1 : 0;
            continue;
        }

        dp[len] = dp[len - 2] + dp[len - 1];

        for (int left = 1; left < (int) str.size(); left++)
            if (ends_with(len - 2, str, 0, left) && starts_with(len - 1, str, left, str.size() - left))
                dp[len]++;

        dp[len] = min(dp[len], LL_INF);
    }

    return dp[n];
}

int main() {
    prepare();
    int N, M;
    long long K;
    cin >> N >> K >> M;
    string answer = "";

    for (int i = 0; i < M; i++) {
        long long zeros = occurrences(N, answer + '0');
        int exact = answer != "" && ends_with(N, answer, 0, answer.size());

        if (K <= exact) {
            break;
        } else if (K <= exact + zeros) {
            K -= exact;
            answer += '0';
        } else {
            K -= exact + zeros;
            answer += '1';
        }
    }

    cout << answer << '\n';
}