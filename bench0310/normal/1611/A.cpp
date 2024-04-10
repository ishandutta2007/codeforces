#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        auto e=[&](int i)->bool{return (1-((s[i]-'0')&1));};
        int p=-1;
        for(int i=n-1;i>=0;i--) if(e(i)) p=i;
        int res=[&]()->int
        {
            if(p==-1) return -1;
            else if(e(n-1)) return 0;
            else if(e(0)) return 1;
            else return 2;
        }();
        cout << res << "\n";
    }
    return 0;
}