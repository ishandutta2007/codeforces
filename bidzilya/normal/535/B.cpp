#include <bits/stdc++.h>
using namespace std;

const int kMaxLen = 9;

vector<int> all_happy_numbers;

void GenerateAllHappyNumbers(int x, int len)
{
    if (len > 0) {
        all_happy_numbers.push_back(x);
    }
    if (len < kMaxLen) {
        GenerateAllHappyNumbers(x * 10 + 4, len + 1);
        GenerateAllHappyNumbers(x * 10 + 7, len + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    GenerateAllHappyNumbers(0, 0);
    
    int ans = 0;
    for (int i = 0; i < (int) all_happy_numbers.size(); ++i) {
        if (all_happy_numbers[i] <= n) {
            ++ans;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}