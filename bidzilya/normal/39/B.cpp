#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i=1,cur=1; i<=n; i++)
    {
        int x;
        cin >> x;
        if (x==cur)
        {
            cur++;
            ans.push_back(2000+i);
        }
    }
    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}