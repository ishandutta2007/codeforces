#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string IntToString(int x) {
    if (x == 0) {
        return "0";
    }
    string result;
    while (x > 0) {
        result.push_back((char)((x % 10) + '0'));
        x /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void Add(vector<int>& nums, const string& s, int add) {
    for (int i = 0; i < (int) s.length(); ++i) {
        nums[s[i] - '0'] += add;
    }
}

bool Check(const vector<int>& nums) {
    for (int i = 0; i < (int) nums.size(); ++i) {
        if (nums[i] < 0) {
            return false;
        }
    }
    return true;
}

bool IsSmaller(const string& s1, const string& s2) {
    if (s1.length() < s2.length()) {
        return true;
    }
    if (s1.length() > s2.length()) {
        return false;
    }
    return s1 < s2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;
    int n = s.length();

    if (n == 2) {
        if (s == "01" || s == "10") {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<int> nums(10, 0);

    Add(nums, s, 1);

    cin >> s;
    Add(nums, s, -1);

    string result = "";
    for (int lenLen = 0; lenLen <= 7; ++lenLen) {
        int len = n - lenLen;

        if (len <= 0) {
            continue;
        }

        string strLenRepr = IntToString(len);

        if (strLenRepr.length() != lenLen) {
            continue;
        }

        Add(nums, strLenRepr, -1);

        if (!Check(nums)) {
            Add(nums, strLenRepr, 1);
            continue;
        }

        if (s[0] != '0') {
            string endedResult = s;
            endedResult.reserve(len);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < nums[i]; ++j) {
                    endedResult.push_back((char)(i + '0'));
                }
            }
            if (result.length() == 0 || IsSmaller(endedResult, result)) {
                result = endedResult;
            }
        }

        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += nums[i];
        }

        if (sum > 0) {
            int firstId = -1;
            for (int i = 1; i < 10; ++i) {
                if (nums[i] > 0) {
                    firstId = i;
                    break;
                }
            }

            if (firstId != -1) {
                string startedResult = "";
                startedResult.reserve(len);
                --nums[firstId];
                startedResult.push_back((char)(firstId + '0'));
                for (int i = 0; i < s[0] - '0'; ++i) {
                    for (int j = 0; j < nums[i]; ++j) {
                        startedResult.push_back((char)(i + '0'));
                    }
                }
                int first = s[0] - '0';
                int second = -1;
                for (int i = 1; i < (int) s.length(); ++i) {
                    if (s[i] != s[i - 1]) {
                        second = s[i] - '0';
                        break;
                    }
                }
                if (second == -1) {
                    nums[first] += s.length();
                    for (int i = first; i < 10; ++i) {
                        for (int j = 0; j < nums[i]; ++j) {
                            startedResult.push_back((char)(i + '0'));
                        }
                    }
                    nums[first] -= s.length();
                } else {
                    if (second > first) {
                        for (int i = 0; i < nums[s[0] - '0']; ++i) {
                            startedResult.push_back(s[0]);
                        }
                        startedResult.insert(startedResult.end(), s.begin(), s.end());
                        for (int i = s[0] - '0' + 1; i < 10; ++i) {
                            for (int j = 0; j < nums[i]; ++j) {
                                startedResult.push_back((char)(i + '0'));
                            }
                        }
                    } else {
                        startedResult.insert(startedResult.end(), s.begin(), s.end());
                        for (int i = first; i < 10; ++i) {
                            for (int j = 0; j < nums[i]; ++j) {
                                startedResult.push_back((char)(i + '0'));
                            }
                        }
                    }
                }
                if (result.length() == 0 || IsSmaller(startedResult, result)) {
                    result = startedResult;
                }
                ++nums[firstId];
            }
        }

        Add(nums, strLenRepr, 1);
    }

    cout << result << endl;

    return 0;
}