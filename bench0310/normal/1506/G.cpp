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
        set<char> tmp;
        for(char c:s) tmp.insert(c);
        vector<char> opt(tmp.begin(),tmp.end());
        reverse(opt.begin(),opt.end());
        while(!opt.empty())
        {
            int n=s.size();
            vector<int> one(26,0);
            for(int i=n-1;i>=0;i--) one[s[i]-'a']=i;
            vector<int> two(26,n);
            for(int i=0;i<n;i++) two[s[i]-'a']=i;
            vector<int> pre(26,n);
            pre[0]=two[0];
            for(int i=1;i<26;i++) pre[i]=min(pre[i-1],two[i]);
            vector<int> suf(26,n);
            suf[25]=two[25];
            for(int i=24;i>=0;i--) suf[i]=min(suf[i+1],two[i]);
            auto val=[&](int x)->int
            {
                int mn=n;
                if(x>0) mn=min(mn,pre[x-1]);
                if(x<25) mn=min(mn,suf[x+1]);
                return mn;
            };
            for(char c:opt)
            {
                if(one[c-'a']<val(c-'a'))
                {
                    string ns;
                    for(int i=one[c-'a']+1;i<n;i++) if(s[i]!=c) ns+=s[i];
                    cout << c;
                    s=ns;
                    opt.erase(find(opt.begin(),opt.end(),c));
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}