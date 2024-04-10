#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 3;
    while ((k+1)*k/2 <= n)k++;
    vector<vector<int> > ans(k);
    int c = 1;
    for (int i=0; i<k; i++)
        for (int j=i+1; j<k; j++)
        {
            ans[i].push_back(c);
            ans[j].push_back(c);
            c++;
        }
    while (c<=n)
    {
        ans[k-1].push_back(c);
        c++;
    }
    cout << k << endl;
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}