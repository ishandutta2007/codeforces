#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r;
    cin >> r;
    vector<int> v={-50,1200,1400,1600,1900,2100,2300,2400,2600,3000};
    for(int i=0;i+1<(int)v.size();i++) if(v[i]<=r&&r<v[i+1]) cout << v[i+1] << "\n";
    return 0;
}