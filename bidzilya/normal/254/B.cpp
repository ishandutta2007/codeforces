#include <bits/stdc++.h>
using namespace std;

const int kAmountOfMonths = 12;

const int kAmountOfDaysInMonth[kAmountOfMonths] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

struct Date
{
    int d, m, y;

    Date(int d, int m, int y) :
        d(d),
        m(m),
        y(y)
    {
    }

    Date() :
        d(0),
        m(0),
        y(2013)
    {
    }
};

int GetAmountOfDaysInMonth(Date date)
{
    if (IsLeapYear(date.y) && date.m == 1) {
        return kAmountOfDaysInMonth[date.m] + 1;
    }
    return kAmountOfDaysInMonth[date.m];
}

void NextDate(Date& date)
{
    ++date.d;
    if (date.d == GetAmountOfDaysInMonth(date)) {
        date.d = 0;
        ++date.m;

        if (date.m == 12) {
            date.m = 0;
            ++date.y;
        }
    }
}

void PrevDate(Date& date)
{
    --date.d;
    if (date.d < 0) {
        --date.m;
        if (date.m < 0) {
            date.m = 11;
            --date.y;
        }
        date.d = GetAmountOfDaysInMonth(date) - 1;
    }
}

bool operator < (const Date& lhs, const Date& rhs)
{
    return lhs.y < rhs.y ||
        (lhs.y == rhs.y && lhs.m < rhs.m) ||
        (lhs.y == rhs.y && lhs.m == rhs.m && lhs.d < rhs.d);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<Date, int> ans;

    for (int i = 0; i < n; ++i) {
        int m, d, p, t;
        cin >> m >> d >> p >> t;
        --m;
        --d;
        Date cur(d, m, 2013);
        for (int i = 0; i < t; ++i) {
            PrevDate(cur);
            ans[cur] += p;
        }
    }

    int gl_ans = 0;
    for (const auto& itr: ans) {
        gl_ans = max(gl_ans, itr.second);
    }

    cout << gl_ans << endl;

    return 0;
}