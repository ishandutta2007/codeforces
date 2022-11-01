#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> k(n+1,0);
    for(int i=1;i<=n;i++) cin >> k[i];
    vector<array<int,3>> v;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) v.push_back({abs(k[i]-k[j]),i,j});
    sort(v.begin(),v.end(),greater<>());
    for(auto [d,i,j]:v)
    {
        if(k[i]>k[j]) swap(i,j);
        cout << "? " << j << " " << i << "\n";
        cout.flush();
        string s;
        cin >> s;
        if(s=="Yes")
        {
            cout << "! " << i << " " << j << "\n";
            cout.flush();
            exit(0);
        }
    }
    cout << "! 0 0\n";
    cout.flush();
    return 0;
}