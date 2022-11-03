#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 2e5;
const int MAX_A = 2e5;

struct TPairCmp {
public:
    bool operator () (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dels(MAX_A + 1);

    for (int i = 1; i <= MAX_A; ++i) {
        for (int j = i; j <= MAX_A; j += i) {
            dels[j].push_back(i);
        }
    }

    vector<vector<int>> delPoses(MAX_A + 1);

    vector<int> leftCount(MAX_A + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j : dels[a[i]]) {
            delPoses[j].push_back(i);
        }
    }

    set<pair<int, int>, TPairCmp> s; // (pos, del)
    long long setSum = 0;

    auto getBorder = [&] (int del) {
        int s = delPoses[del].size();
        if (s < 2) {
            return -1;
        }
        if (leftCount[del] >= 2) {
            return n - 1;
        }
        if (leftCount[del] == 0) {
            return delPoses[del][s - 2] - 1;
        } else if (leftCount[del] == 1) {
            return delPoses[del][s - 1] - 1;
        }
        return -1;
    };

    auto isInSet = [&] (int del) {
        int border = getBorder(del);
        return s.find(make_pair(border, del)) != s.end();
    };

    auto delFromSet = [&] (int pos, int del) {
        int border = getBorder(del);

        auto itr = s.find(make_pair(border, del));

        if (itr == s.end()) {
            return;
        }

        if (itr == s.begin()) {
            setSum -= 1LL * (itr->first - pos + 1) * itr->second;
            auto newItr = itr;
            ++newItr;
            if (newItr != s.end()) {
                setSum += 1LL * (itr->first - pos + 1) * newItr->second;
            }
            s.erase(itr);
        } else {
            auto lowItr = itr;
            --lowItr;

            auto upItr = itr;
            ++upItr;

            setSum -= 1LL * (itr->first - lowItr->first) * itr->second;

            if (upItr != s.end()) {
                setSum += 1LL * (itr->first - lowItr->first) * upItr->second;
            }

            s.erase(itr);
        }
    };

    auto insertToSet = [&] (int pos, int del) {
        int border = getBorder(del);

        auto itr = s.insert(make_pair(border, del)).first;

        auto upItr = itr;
        ++upItr;

        if (upItr != s.end()) {
            if (upItr->second > del) {
                s.erase(itr);
                return;
            }
            if (itr == s.begin()) {
                setSum -= 1LL * (itr->first - pos + 1) * upItr->second;
                setSum += 1LL * (itr->first - pos + 1) * itr->second;
                return;
            } else {
                auto lowItr = itr;
                --lowItr;
                setSum -= 1LL * (itr->first - lowItr->first) * upItr->second;
                setSum += 1LL * (itr->first - lowItr->first) * itr->second;
            }
        } else {
            if (itr == s.begin()) {
                setSum += 1LL * (itr->first - pos + 1) * itr->second;
                return;
            } else {
                auto lowItr = itr;
                --lowItr;
                setSum += 1LL * (itr->first - lowItr->first) * itr->second;
            }
        }

        vector<pair<int, int>> values;

        auto lowItr = itr;
        --lowItr;
        while (lowItr->second < itr->second) {
            int nextPos;
            if (lowItr == s.begin()) {
                nextPos = pos;
            } else {
                auto temp = lowItr;
                --temp;
                nextPos = temp->first + 1;
            }
            int curPos = lowItr->first;
            setSum -= 1LL * (curPos - nextPos + 1) * lowItr->second;
            setSum += 1LL * (curPos - nextPos + 1) * itr->second;
            values.push_back(*lowItr);
            if (lowItr == s.begin()) {
                break;
            } else {
                --lowItr;
            }
        }

        for (const auto& x : values) {
            s.erase(x);
        }
    };

    for (int i = 1; i <= MAX_A; ++i) {
        if (getBorder(i) != -1) {
            insertToSet(0, i);
        }
    }

    long long result = 0;
    for (int pos = 0; pos < n; ++pos) {
        result += setSum;
        for (int del : dels[a[pos]]) {
            if (isInSet(del)) {
                delFromSet(pos, del);
            }
        }
        while (!s.empty() && s.begin()->first == pos) {
            delFromSet(pos, s.begin()->second);
        }
        for (int del : dels[a[pos]]) {
            ++leftCount[del];
        }
        if (pos + 1 < n) {
            if (!s.empty()) {
                setSum -= s.begin()->second;
            }
            for (int del : dels[a[pos]]) {
                if (getBorder(del) >= pos + 1) {
                    insertToSet(pos + 1, del);
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}