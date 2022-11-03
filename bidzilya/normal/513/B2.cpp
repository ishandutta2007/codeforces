#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Show(const vector<int>& a)
{
    for (int i = 0; i < (int) a.size(); ++i) {
        cout << a[i] + 1 << " ";
    }
}

vector<int> FindAnswer(int n, long long m)
{
    long long all = (1LL << (n - 1));
    vector<int> a(n);
    int l = 0, r = n - 1;
    for (int i = 0; i + 1 < n; ++i) {
        all >>= 1;
        if (m <= all) {
            a[l] = i;
            ++l;
        } else {
            a[r] = i;
            --r;
            m -= all;
        }
    }
    a[l] = n - 1;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    long long m;
    cin >> m;

    Show(FindAnswer(n, m));
    cout << endl;

    return 0;
}