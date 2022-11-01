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
        int sum=0;
        int cnt=0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='(') sum++;
            if(c==')') sum--;
            if(c=='?')
            {
                cnt++;
                v.push_back(i);
            }
        }
        int a=(cnt-sum)/2;
        int b=cnt-a;
        if(min(a,b)>0)
        {
            int idx=0;
            for(int i=0;i<a-1;i++) s[v[idx++]]='(';
            s[v[idx++]]=')';
            s[v[idx++]]='(';
            for(int i=0;i<b-1;i++) s[v[idx++]]=')';
            bool ok=1;
            int tmp=0;
            for(char c:s)
            {
                tmp+=(c=='('?1:-1);
                ok&=(tmp>=0);
            }
            if(ok) cout << "NO\n";
            else cout << "YES\n";
        }
        else cout << "YES\n";
    }
    return 0;
}