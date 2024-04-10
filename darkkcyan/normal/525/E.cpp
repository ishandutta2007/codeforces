#include <bits/stdc++.h>

using namespace std;

const string FILE_NAME = "sticker";

vector<long long int> fnumTable;
void generateFractionalTable(long long int max) {
    fnumTable.resize(0);
    fnumTable.push_back(1);
    fnumTable.push_back(1);
    for (int i = 2; fnumTable[i - 1] <= max; ++i) {
        fnumTable.push_back(fnumTable[i - 1] * i);
        // clog << "frac: " << i << ' ' << fnumTable[i] << endl;
    }
}

long long int n, k, s;
vector<int> arr;

template <typename Callback>
void process(int curInd, int stopInd, int kUsed, long long int sum, Callback &callback) {
    if (kUsed > k) return;
    if (sum > s) return;
    if (curInd == stopInd) {
        callback(sum, kUsed);
        return;
    }
    process(curInd + 1, stopInd, kUsed, sum, callback);  // ignore
    process(curInd + 1, stopInd, kUsed, sum + arr[curInd], callback); // add
    if (arr[curInd] < fnumTable.size() and kUsed < k) {
        process(curInd + 1, stopInd, kUsed + 1, sum + fnumTable[arr[curInd]], callback); // add fraction
    }
}

map<long long int, vector<int> > tmap;
void callback1(long long int sum, int kUsed) {
    // clog << "1: " << sum << ' ' << kUsed << endl;
    if (!tmap.count(sum)) {
        vector<int>& a = tmap[sum] = vector<int>(k + 5, 0);
        a[kUsed] = 1;
    } else {
        tmap[sum][kUsed]++;
    }

}

long long int result = 0;
void callback2(long long int sum, int kUsed) {
    // clog << "2: " << sum << ' ' << kUsed << endl;
    if (!tmap.count(s - sum)) return;
    vector<int> &arr = tmap[s - sum];
    for (int i = k; i >= kUsed; --i) {
        result += arr[k - i];
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;
    #ifndef ONLINE_JUDGE
    ifstream cin((FILE_NAME + ".inp").c_str());
    ofstream cout((FILE_NAME + ".out").c_str());
    #endif

    cin >> n >> k >> s;
    arr.resize(n + 10);
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    generateFractionalTable(s);

    process(0, n / 2, 0, 0, callback1);
    process(n / 2, n, 0, 0, callback2);

    cout << result << '\n';

    return 0;
}