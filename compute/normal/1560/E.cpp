#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
string check(string s, string t)
{
    string ret;
    for(auto u:t)
    {
        ret+=s;
        string nxt;
        for(auto v:s)
        {
            if(v!=u) nxt+=v;
        }
        s=nxt;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        string sv=s;
        vi cnt(26);
        vi vis(26);
        for(auto u:s) cnt[u-'a']++;
        int kd=0;
        for(int i=0;i<26;i++) kd+=!!cnt[i];
        string t;
        bool suc=1;
        int curlen=0;
        for(int i=0;i<kd-1;i++)
        {
            int tar=-1;
            for(int i=s.length()-1;i>=0;i--)
            {
                if(!vis[s[i]-'a'])
                {
                    tar=s[i]-'a';
                    break;
                }
            }
            if(tar==-1||cnt[tar]%(kd-i)!=0)
            {
                suc=0;
                break;
            }
            vis[tar]=1;
            t+='a'+tar;
            curlen+=cnt[tar]/(kd-i);
            for(int j=0;j<curlen;j++) s.pop_back();
        }
        if(!suc) cout<<-1<<'\n';
        else{
            for(auto u:s)
            {
                if(!vis[u-'a'])
                {
                    t+=u;
                    break;
                }
            }
            reverse(t.begin(),t.end());
            if(check(s,t)==sv)
                cout<<s<<" "<<t<<'\n';
            else cout<<-1<<'\n';
        }
    }
}