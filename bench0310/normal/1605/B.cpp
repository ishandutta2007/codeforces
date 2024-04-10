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
        int n;
        cin >> n;
        string s;
        cin >> s;
        array<int,2> c={0,0};
        for(char a:s) c[a-'0']++;
        vector<int> v;
        for(int i=0;i<n;i++) if((i<c[0]&&s[i]=='1')||(i>=c[0]&&s[i]=='0')) v.push_back(i+1);
        if(v.empty()) cout << "0\n";
        else
        {
            cout << "1\n";
            cout << v.size();
            for(int a:v) cout << " " << a;
            cout << "\n";
        }
    }
    return 0;
}