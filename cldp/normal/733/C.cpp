#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int X[1000001], Y[1000001];

int main() {
    int N, M;
    cin >> N;
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &X[i]);
        sum += X[i];
    }
    cin >> M;
    for (int i = 1; i <= M; ++i) {
        scanf("%d", &Y[i]);
        sum -= Y[i];
    }
    if (sum != 0) {
        cout << "NO" << endl;
        return 0; 
    }

    vector<string> ans;

    int j = 1, k = 1;
    for (int i = 1; i <= M; ++i) {
        long long cnt = 0;
        while (cnt < Y[i]) cnt += X[j++];
        if (cnt != Y[i]) {
            cout << "NO" << endl;
            return 0;
        }

        int T = X[k];
        for (int t = k + 1; t < j; ++t) {
            if (X[t] > T) T = X[t];
        }

        int L = -1, R = -1;
        for (int t = k; t < j; ++t) {
            if (X[t] == T) {
                if (t > k && X[t - 1] != T) {
                    L = t; 
                    break;
                }
                if (t < j - 1 && X[t + 1] != T) {
                    R =  t;
                    break;
                }
            }
        }

        if (L == -1 && R == -1 && k + 1 != j) {
            cout << "NO" << endl;
            return 0;
        }

        if (L != -1) {
            for (int t = L; t > k; --t) {
                ans.push_back(to_string(t - (k - i)) + " L");
             //   printf("%d L\n", t - (k - i));
            }
            for (int t = L; t < j - 1; ++t) {
                ans.push_back(to_string(L - (k - i) - (L - k)) + " R");
             //   printf("%d R\n", t - (k - i) - (L - k));
            }
        } else 
        if (R != -1) {
            for (int t = R; t < j - 1; ++t) {
                ans.push_back(to_string(t - (k - i) - (t - R)) + " R");
               // printf("%d R\n", t - (k - i) - (t - R));
            }
            for (int t = R; t > k; --t) {
                ans.push_back(to_string(t - (k - i)) + " L");
             //   printf("%d L\n", t - (k - i));
            }
        }

        k = j;
    }

    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); ++i) printf("%s\n", ans[i].c_str());
    return 0;
}