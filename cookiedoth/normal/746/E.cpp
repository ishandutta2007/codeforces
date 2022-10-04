/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair

using namespace std;

const int mx = 300000;
int n, m, ev, od, min_even, min_odd, ans = 0, p, ma[mx], changed[mx];
pair<int, int> a[mx];
multiset<int> el;

void change_even(int i) {
    changed[i] = 1;
    ans++;
    while (el.find(min_even) != el.end()) {
        min_even += 2;
    }
    el.erase(el.find(a[i].first));
    el.insert(min_even);
    a[i].first = min_even;
}

void change_odd(int i) {
    changed[i] = 1;
    ans++;
    while (el.find(min_odd) != el.end()) {
        min_odd += 2;
    }
    el.erase(el.find(a[i].first));
    el.insert(min_odd);
    a[i].first = min_odd;
}

void change(int i) {
    if (a[i].first % 2 == 0) {
        if (ev > od) {
            change_odd(i);
            od++;
            ev--;
        }
        else change_even(i);
    }
    else {
        if (od > ev) {
            change_even(i);
            od--;
            ev++;
        }
        else change_odd(i);
    }
}


int main()
{
    int temp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a[i] = mp(temp, i);
        el.insert(temp);
        changed[i] = 0;
    }
    sort(a, a + n);
    ev = 0;
    od = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].first % 2 == 0) ev++;
        else od++;
    }
    min_even = 2;
    min_odd = 1;
    p = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].first != a[p].first) {
            p = i;
        }
        else {
            change(i);
        }
    }
    min_even = 2;
    min_odd = 1;
    for (int i = 1; i < n; ++i) {
        if ((a[i].first % 2 == 0) && (ev > od)) {
            change_odd(i);
            od++;
            ev--;
        }
        else {
            if ((a[i].first % 2 == 1) && (od > ev)) {
                change_even(i);
                ev++;
                od--;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if ((a[i].first > m) && (changed[i] > 0)) {
            cout << -1;
            return 0;
        }
        ma[a[i].second] = a[i].first;
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        cout << ma[i] << " ";
    }
    return 0;
}