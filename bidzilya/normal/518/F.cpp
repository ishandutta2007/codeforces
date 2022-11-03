#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const char kOccupied = '#';
const char kFree = '.';

void Rotate(vector<vector<char> >& a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<char> > r(m, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            r[j][n - i - 1] = a[i][j];
        }
    }
    a = r;
}

long long Get1Inner(const vector<vector<char> >& a)
{
    int n = a.size();
    int m = a[0].size();

    long long ans = 0;
    for (int i = 1; i + 1 < m; ++i) {
        bool good = true;

        for (int j = 0; j < n; ++j) {
            if (a[j][i] == kOccupied) {
                good = false;
                break;
            }
        }

        if (good) {
            ++ans;
        }
    }

    return ans;
}

long long Get1(vector<vector<char> > a)
{
    long long ans = 0;
    ans += Get1Inner(a);
    Rotate(a);
    ans += Get1Inner(a);
    return ans;
}

inline int GetS(const vector<int>& a, int l, int r)
{
    if (l == 0) {
        return a[r];
    }
    return a[r] - a[l - 1];
}

vector<vector<int> > GetStlSum(const vector<vector<char> >& a)
{
    int n = a.size();
    int m = a[0].size();

    vector<vector<int> > stl_sum(m, vector<int>(n));
    for (int j = 0; j < m; ++j) {
        stl_sum[j][0] = (a[0][j] == kOccupied);
        for (int i = 1; i < n; ++i) {
            stl_sum[j][i] = stl_sum[j][i - 1] + (a[i][j] == kOccupied);
        }
    }
    return stl_sum;
}

vector<vector<int> > GetStrSum(const vector<vector<char> >& a)
{
    int n = a.size();
    int m = a[0].size();

    vector<vector<int> > str_sum(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        str_sum[i][0] = (a[i][0] == kOccupied);
        for (int j = 1; j < m; ++j) {
            str_sum[i][j] = str_sum[i][j - 1] + (a[i][j] == kOccupied);
        }
    }
    return str_sum;
}

long long Get2(const vector<vector<char> >& a)
{
    int n = a.size();
    int m = a[0].size();

    vector<vector<int> > stl_sum = GetStlSum(a);
    vector<vector<int> > str_sum = GetStrSum(a);

    long long ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            int left_sum = GetS(str_sum[i], 0, j);
            int right_sum = GetS(str_sum[i], j, m - 1);

            int up_sum = GetS(stl_sum[j], 0, i);
            int down_sum = GetS(stl_sum[j], i, n - 1);

            if (left_sum == 0 && up_sum == 0) {
                ++ans;
            }
            if (left_sum == 0 && down_sum == 0) {
                ++ans;
            }
            if (right_sum == 0 && up_sum == 0) {
                ++ans;
            }
            if (right_sum == 0 && down_sum == 0) {
                ++ans;
            }
        }
    }
    return ans;
}

long long Get3Inner(const vector<vector<char> >& a)
{
    int n = a.size();
    int m = a[0].size();

    long long ans = 0;

    vector<vector<int> > stl_sum = GetStlSum(a);
    for (int i = 1; i + 1 < n; ++i) {
        for (int lj = 1; lj + 1 < m; ) {
            if (a[i][lj] == kOccupied) {
                ++lj;
                continue;
            }
            int rj = lj;
            while (rj + 1 + 1 < m && a[i][rj + 1] == kFree) {
                ++rj;
            }

            long long sum = 0;
            for (int t = lj; t <= rj; ++t) {
                int up_sum = GetS(stl_sum[t], 0, i);

                if (up_sum == 0) {
                    ans += sum;
                }

                int down_sum = GetS(stl_sum[t], i, n - 1);

                if (down_sum == 0) {
                    ++sum;
                }
            }

            sum = 0;
            for (int t = rj; t >= lj; --t) {
                int up_sum = GetS(stl_sum[t], 0, i);

                if (up_sum == 0) {
                    ans += sum;
                }

                int down_sum = GetS(stl_sum[t], i, n - 1);

                if (down_sum == 0) {
                    ++sum;
                }
            }

            lj = rj + 1;
        }
    }
    return ans;
}

long long Get3(vector<vector<char> > a)
{
    long long ans = 0;
    ans += Get3Inner(a);
    Rotate(a);
    ans += Get3Inner(a);
    return ans;
}

long long Get4Inner(const vector<vector<char> > &a)
{
    int n = a.size();
    int m = a[0].size();

    long long ans = 0;

    vector<vector<int> > stl_sum = GetStlSum(a);
    for (int i = 1; i + 1 < n; ++i) {
        for (int lj = 1; lj + 1 < m; ) {
            if (a[i][lj] == kOccupied) {
                ++lj;
                continue;
            }

            int rj = lj;
            while (rj + 1 + 1 < m && a[i][rj + 1] == kFree) {
                ++rj;
            }

            long long sum = 0;
            for (int t = rj; t >= lj; --t) {
                int up_sum = GetS(stl_sum[t], 0, i);
                if (up_sum == 0) {
                    ans += sum;
                }

                if (t + 1 <= rj) {
                    int up_sum = GetS(stl_sum[t + 1], 0, i);

                    if (up_sum == 0) {
                        ++sum;
                    }
                }
            }

            lj = rj + 1;
        }
    }
    return ans;
}

long long Get4(vector<vector<char> > a)
{
    long long ans = 0;
    ans += Get4Inner(a);
    Rotate(a);
    ans += Get4Inner(a);
    Rotate(a);
    ans += Get4Inner(a);
    Rotate(a);
    ans += Get4Inner(a);
    return ans;
}

void Show(const vector<vector<char> >& a)
{
    cout << endl;
    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = 0; j < (int) a[0].size(); ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    long long ans = 0;

    ans += Get1(a);
    ans += Get2(a);
    ans += Get3(a);
    ans += Get4(a);

    cout << ans << endl;

    return 0;
}