#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>cnt(n,0);
    for(int i = 0; i < m;i ++)
    {
        int a;
        cin >> a;
        cnt[a-1]++;
    }
    cout<< * min_element(cnt.begin(),cnt.end());
    return 0;
}