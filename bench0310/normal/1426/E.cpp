#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array<int,3> a,b;
    for(int i=0;i<3;i++) cin >> a[i];
    for(int i=0;i<3;i++) cin >> b[i];
    auto mn=[&]()->int
    {
        int res=0;
        for(int i=0;i<3;i++) res=max(res,a[i]+b[(i+1)%3]-n);
        return res;
    };
    auto mx=[&]()->int
    {
        int res=0;
        for(int i=0;i<3;i++) res+=min(a[i],b[(i+1)%3]);
        return res;
    };
    cout << mn() << " " << mx() << "\n";
    return 0;
}