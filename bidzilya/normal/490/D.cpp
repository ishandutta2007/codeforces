#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int> > Factorize(int n)
{
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    vector<pair<int, int> > result;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            result.push_back(make_pair(0, i));
            while (n % i == 0) {
                n /= i;
                ++result.back().first;
            }
        }
    }
    
    if (n > 1) {
        result.push_back(make_pair(1, n));
    }
    
    return result;
}

int GetDegree(int x, int n)
{
    int result = 0;
    while (x % n == 0) {
        ++result;
        x /= n;
    }
    return result;
}

vector<pair<int, int> > Merge(const vector<pair<int, int> >& f1, 
                            const vector<pair<int, int> >& f2)
{
    vector<pair<int, int> > result;
    for (int i = 0, j = 0; i < (int) f1.size() || j < (int) f2.size(); ) {
        if (i < (int) f1.size() && j < (int) f2.size()) {
            if (f1[i].second == f2[j].second) {
                result.push_back(make_pair(f1[i].first + f2[j].first, f1[i].second));
                ++i;
                ++j;
            } else if (f1[i].second < f2[j].second) {
                result.push_back(f1[i]);
                ++i;
            } else {
                result.push_back(f2[j]);
                ++j;
            }
        } else if (i < (int) f1.size()) {
            result.push_back(f1[i]);
            ++i;
        } else if (j < (int) f2.size()) {
            result.push_back(f2[j]);
            ++j;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a1, b1;
    int a2, b2;
    
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    
    vector<pair<int, int> > fa1 = Factorize(a1),
                            fb1 = Factorize(b1),
                            fa2 = Factorize(a2),
                            fb2 = Factorize(b2);

    vector<pair<int, int> > fact1 = Merge(fa1, fb1);
    vector<pair<int, int> > fact2 = Merge(fa2, fb2);
    
    if (fact1 != fact2) {
        cout << -1 << endl;
        return 0;
    }

    int cnt2_first = GetDegree(a1, 2) + GetDegree(b1, 2);
    int cnt3_first = GetDegree(a1, 3) + GetDegree(b1, 3);
    
    int cnt2_second = GetDegree(a2, 2) + GetDegree(b2, 2);
    int cnt3_second = GetDegree(a2, 3) + GetDegree(b2, 3);

    long long ans_a1 = a1;
    long long ans_b1 = b1;
    long long ans_a2 = a2;
    long long ans_b2 = b2;

    int ans = 0;
    
    while (cnt3_first != cnt3_second) {
        if (cnt3_first > cnt3_second) {
            if (ans_a1 % 3 == 0) {
                ans_a1 /= 3;
                ans_a1 *= 2;
            } else {
                ans_b1 /= 3;
                ans_b1 *= 2;
            }
            ++cnt2_first;
            --cnt3_first;
        } else {
            if (ans_a2 % 3 == 0) {
                ans_a2 /= 3;
                ans_a2 *= 2;
            } else {
                ans_b2 /= 3;
                ans_b2 *= 2;
            }
            ++cnt2_second;
            --cnt3_second;
        }
        ++ans;
    }
    
    while (cnt2_first != cnt2_second) {
        if (cnt2_first > cnt2_second) {
            if (ans_a1 % 2 == 0) {
                ans_a1 /= 2;
            } else {
                ans_b1 /= 2;
            }
            --cnt2_first;
        } else {
            if (ans_a2 % 2 == 0) {
                ans_a2 /= 2;
            } else {
                ans_b2 /= 2;
            }
            --cnt2_second;
        }
        ++ans;
    }
    
    cout << ans << endl;
    cout << ans_a1 << " " << ans_b1 << endl;
    cout << ans_a2 << " " << ans_b2 << endl;
    
    return 0;
}