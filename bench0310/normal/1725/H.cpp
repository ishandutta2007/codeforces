#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[2];
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        a%=3;
        v[a>=1].push_back(i);
    }
    int c=0;
    string col(n+1,'$');
    for(int j=0;j<2;j++)
    {
        for(int x:v[j])
        {
            c++;
            col[x]="01"[c>n/2];
        }
    }
    int z=-1;
    if((int)v[0].size()>=n/2) z=2;
    else z=0;
    cout << z << "\n";
    cout << col.substr(1,n) << "\n";
    return 0;
}