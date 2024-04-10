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
        vector<int> p(26,0);
        int k;
        cin >> k;
        for(int i=0;i<k;i++)
        {
            char c;
            cin >> c;
            p[c-'a']=1;
        }
        int mx=0;
        int nxt=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nxt!=-1) mx=max(mx,nxt-i);
            if(p[s[i]-'a']) nxt=i;
        }
        cout << mx << "\n";
    }
    return 0;
}