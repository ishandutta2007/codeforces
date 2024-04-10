#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    int n, i, x;
    deque<int> mx, mn;
    queue<int> och;
    cin >> n;
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        while (!mx.empty() && mx.back() < x)
        {
            mx.pop_back();
        }
        mx.push_back(x);
        while (!mn.empty() && mn.back() > x)
        {
            mn.pop_back();
        }
        mn.push_back(x);
        och.push(x);
        while (!och.empty() && mn.front() + 1 < mx.front())
        {
            x = och.front();
            och.pop();
            if (mn.front() == x)
                mn.pop_front();
            if (mx.front() == x)
                mx.pop_front();
        }
//        cout <<
        ans = max(ans, (int) och.size());
    }
    cout << ans << endl;
    return 0;
}