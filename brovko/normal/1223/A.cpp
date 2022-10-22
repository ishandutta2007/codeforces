#include <bits/stdc++.h>
using namespace std;
long long q, n, m;
vector <long long> ans;

int main()
{
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> n;
        m=n;
        if(n%2)
            m=n+1;
        if(n<4)
            m=4;
        ans.push_back(m-n);
    }
    for(int i=0;i<q;i++)
        cout << ans[i] << "\n";
    return 0;
}