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
        int mn=9;
        vector<int> c(10,0);
        for(int i=n-1;i>=0;i--)
        {
            mn=min(mn,s[i]-'0');
            if((s[i]-'0')==mn) c[s[i]-'0']++;
            else c[min(s[i]-'0'+1,9)]++;
        }
        for(int i=0;i<10;i++) cout << string(c[i],char('0'+i));
        cout << "\n";
    }
    return 0;
}