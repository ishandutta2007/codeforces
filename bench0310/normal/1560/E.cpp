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
        string ini;
        cin >> ini;
        vector<int> cnt(26,0);
        int n=0;
        vector<bool> vis(26,0);
        for(char x:ini) vis[x-'a']=1;
        for(int i=0;i<26;i++) n+=(vis[i]);
        string s=ini;
        string ord;
        bool bad=0;
        while(!s.empty())
        {
            char c=s.back();
            ord+=c;
            int now=0;
            for(char x:s) now+=(c==x);
            if((now%n)==0) cnt[c-'a']=(now/n);
            else bad=1;
            string ns;
            for(char x:s) if(x!=c) ns+=x;
            s=ns;
            n--;
        }
        reverse(ord.begin(),ord.end());
        int len=0;
        for(int i=0;i<26;i++) len+=cnt[i];
        if((int)ini.size()>=len)
        {
            s=ini.substr(0,len);
            for(char c:s) cnt[c-'a']--;
            for(int i=0;i<26;i++) bad|=(cnt[i]!=0);
        }
        else bad=1;
        string opt;
        for(char c:ord)
        {
            opt+=s;
            string ns;
            for(char x:s) if(x!=c) ns+=x;
            s=ns;
        }
        bad|=(ini!=opt);
        if(!bad) cout << ini.substr(0,len) << " " << ord << "\n";
        else cout << "-1\n";
    }
    return 0;
}