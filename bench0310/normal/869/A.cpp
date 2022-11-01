#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2*n,0);
    set<int> s;
    for(int i=0;i<2*n;i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    bool x=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(s.find(a[i]^a[j+n])!=s.end()) x=!x;
    if(x==0) cout << "Karen\n";
    else cout << "Kuroni\n";
    return 0;
}