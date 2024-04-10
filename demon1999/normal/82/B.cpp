#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
unsigned int i, j, n, m, k, k1, k2 = 1, ko[4];
vector <int> a[201], b[201];
map<vector<int>, int> ml;
int main()
{
    //ifstream cin("input.txt");
    cin >> n;
    for (i = 0; i < n * (n - 1) / 2; i++)
    {
        cin >> k;
        if(n == 2)cout << k - 1 <<  " ";
        for (j = 0; j < k; j++)
        {
            cin >> m;
            if(n == 2 && j < k - 1)cout << m << " ";
            if(n == 2 && j == k - 1)cout << endl << "1 " << m;
            a[m].push_back(i);
        }
    }
    if(n == 2)return 0;
    for(int i = 1; i <= 200; i++)
    {
        if(a[i].size() == 0)continue;
        if(ml[a[i]] == 0)
        {
            ml[a[i]] = k2;
            k2 ++;
        }
        b[ml[a[i]]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << b[i].size() << " ";
        for(int j = 0; j < b[i].size(); j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}