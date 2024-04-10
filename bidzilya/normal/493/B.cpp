#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    vector<int> first;

    vector<int> second;

    cin >> n;

    int last;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            first.push_back(x);
            last = 0;
        } else {
            second.push_back(-x);
            last = 1;
        }
    }

    long long first_sum = 0;
    for (auto x : first) {
        first_sum += x;
    }

    long long second_sum = 0;
    for (auto x : second) {
        second_sum += x;
    }

    if (first_sum > second_sum) {
        cout << "first" << endl;
        return 0;
    }

    if (second_sum > first_sum) {
        cout << "second" << endl;
        return 0;
    }

    for (int i = 0; i < (int) min(first.size(), second.size()); ++i) {
        if (first[i] > second[i]) {
            cout << "first" << endl;
            return 0;
        } else if (first[i] < second[i]) {
            cout << "second" << endl;
            return 0;
        }
    }

    if (first.size() < second.size()) {
        cout << "first" << endl;
        return 0;
    }

    if (second.size() < first.size()) {
        cout << "second" << endl;
        return 0;
    }

    if (last == 0) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }


    return 0;
}