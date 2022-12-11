#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,i, j;
    cin >> n;
    vector<int> ans;
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j < i; j++)
            if (i % j == 0) break;
        if (i != j) continue;
        j = i;
        while (j <= n)
        {
            ans.push_back(j);
            j *= i;
        }
    }
    cout << ans.size() << endl;
    for (auto w : ans)
    {
        cout << w << ' ';
    }
    return 0;
}