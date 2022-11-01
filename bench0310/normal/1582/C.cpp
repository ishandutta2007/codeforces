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
        int res=n;
        for(char c='a';c<='z';c++)
        {
            string one;
            vector<int> v;
            int now=0;
            int all=0;
            for(char a:s)
            {
                if(a==c)
                {
                    now++;
                    all++;
                }
                else
                {
                    v.push_back(now);
                    now=0;
                    one+=a;
                }
            }
            v.push_back(now);
            string two=one;
            ranges::reverse(two);
            if(one!=two) continue;
            int keep=0;
            int sz=v.size();
            for(int i=0;i<=sz-1-i;i++) keep+=(1+(i<sz-1-i))*min(v[i],v[sz-1-i]);
            res=min(res,all-keep);
        }
        if(res==n) res=-1;
        cout << res << "\n";
    }
    return 0;
}