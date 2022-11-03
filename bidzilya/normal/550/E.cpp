#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

stringstream ans;

bool CanGet0(int, int);
bool CanGet1(int, int);

bool CanGet1(int l, int r)
{
    if (a[r] == 1) {
        ans << a[l];
        for (int i = l + 1; i <= r; ++i) {
            ans << "->";
            ans << a[i];
        }
        return true;
    }
    if (l == r) {
        return false;
    }
    int pos = -1;
    for (int i = r - 1; i >= l; --i) {
        if (a[i] == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        return false;
    }
    if (l < pos) {
        ans << a[l];
        for (int i = l + 1; i < pos; ++i) {
            ans << "->";
            ans << a[i];
        }
        ans << "->";
    }
    if (pos + 1 == r) {
        ans << "(0->0)";
    } else {
        ans << "(0->(1";
        for (int i = pos + 2; i < r; ++i) {
            ans << "->1";
        }
        ans << "->0))";
    }
    return true;
}

bool CanGet0(int l, int r)
{
    if (a[r] != 0) {
        return false;
    }
    if (l == r) {
        ans << 0;
        return true;
    }
    ans << '(';
    if (!CanGet1(l, r - 1)) {
        return false;
    } else {
        ans << ")->0";
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n == 1) {
        if (a[0] == 0) {
            cout << "YES" << endl;
            cout << 0 << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if (CanGet0(0, n - 1)) {
        cout << "YES" << endl;
        cout << ans.str() << endl;
    } else {
        cout << "NO" << endl;
    }
   
    return 0;
}