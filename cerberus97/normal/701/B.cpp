#include <iostream>
#include <set>

using namespace std;

set <int> rows, columns;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m;

    while (m--)
    {
        cin >> x >> y;

        rows.insert(x);
        columns.insert(y);

        cout << ((long long)(n - rows.size())) * (n - columns.size()) << ' ';
    }

    return 0;
}