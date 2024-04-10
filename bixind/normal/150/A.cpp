#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long q, q1;
    cin >> q;
    if (q == 1) {
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    q1 = q;
    vector<int> cnt;
    vector<long long> dl;
    for (long long i = 2; i < 10000000; ++i) {
        int v = 0;
        while (q % i == 0)
            q /= i, ++v;
        if (v != 0) {
            cnt.push_back(v);
            dl.push_back(i);
        }
    }
    if (q != 1) {
        cnt.push_back(1);
        dl.push_back(q);
    }
    if (cnt.size() == 1 && cnt[0] == 1)
    {
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < cnt.size(); ++i) {
        sum += cnt[i];
    }
    if (cnt.size() >= 2 && sum > 2) {
        cout << 1 << endl;
        cout << dl[0] * dl[1] << endl;
        return 0;
    }
    if (cnt.size() == 1 && cnt[0] > 2) {
        cout << 1 << endl;
        cout << dl[0] * dl[0] << endl;
        return 0;
    }
    cout << 2 << endl;
    return 0;
}