#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;

int ans[MAX_N];

void BuildAns() 
{
    ans[0] = 0;
    for (int i = 1; i < MAX_N; ++i) {
        if (i & 1) {
            if (ans[i - 1] == 0) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        } else {
            int x1 = ans[i - 1];
            int x2 = ans[i >> 1];
            ans[i] = 0;
            if (ans[i] == x1 || ans[i] == x2) {
                ++ans[i];
            }
            if (ans[i] == x1 || ans[i] == x2) {
                ++ans[i];
            }
        }
    }
}

int GetAns(int a)
{
    if (a < MAX_N) {
        return ans[a];
    } else {
        if (a & 1) {
            return 0;
        }
        int x = GetAns(a >> 1);
        if (x == 1) {
            return 2;
        } else {
            return 1;
        }
    }
}

int GetAns(int a, int k)
{
    if (k & 1) {
        return GetAns(a);
    } else {
        if (a == 1) {
            return 1;
        }
        if (a == 0) {
            return 0;
        }
        if (a == 2) {
            return 2;
        }
        return 1 - (a & 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BuildAns();

    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans ^= GetAns(a, k);
    }

    string first = "Kevin";
    string second = "Nicky";

    if (ans > 0) {
        cout << first << endl;
    } else {
        cout << second << endl;
    }
    
    return 0;
}