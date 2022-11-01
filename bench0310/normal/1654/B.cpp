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
        array<int,26> cnt;
        cnt.fill(0);
        for(char c:s) cnt[c-'a']++;
        for(int i=0;i<n;i++)
        {
            if(cnt[s[i]-'a']==1)
            {
                cout << s.substr(i) << " \n"[i==n-1];
                break;
            }
            cnt[s[i]-'a']--;
        }
    }
    return 0;
}