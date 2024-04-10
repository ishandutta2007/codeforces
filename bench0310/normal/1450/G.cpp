#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sz,a,b;
    cin >> sz >> a >> b;
    string s;
    cin >> s;
    string t=s;
    ranges::sort(t);
    t.erase(unique(t.begin(),t.end()),t.end());
    int n=t.size();
    vector<int> id(26,-1);
    for(int i=0;i<n;i++) id[t[i]-'a']=i;
    vector<int> l(n,sz);
    vector<int> r(n,-1);
    vector<int> cnt(n,0);
    for(int i=0;i<sz;i++)
    {
        int x=id[s[i]-'a'];
        l[x]=min(l[x],i);
        r[x]=max(r[x],i);
        cnt[x]++;
    }
    vector<int> ord(n);
    for(int i=0;i<n;i++) ord[i]=i;
    ranges::sort(ord,[&](int x,int y){return (l[x]<l[y]);});
    vector<bool> dp((1<<n),0);
    dp[0]=1;
    for(int m=1;m<(1<<n);m++)
    {
        int c=0;
        int tl=sz,tr=-1;
        for(int i=0;i<n;i++)
        {
            if((m&(1<<i))==0) continue;
            c+=cnt[i];
            tl=min(tl,l[i]);
            tr=max(tr,r[i]);
        }
        bool ok=(a*(tr-tl+1)<=b*c);
        int sub=0;
        for(int i=0;i<n;i++)
        {
            if((m&(1<<ord[i]))==0) continue;
            sub|=(1<<ord[i]);
            if(dp[sub]&&dp[m^sub]) dp[m]=1;
            if(ok&&dp[m^(1<<ord[i])]) dp[m]=1;
        }
    }
    string res;
    for(int i=0;i<n;i++) if(dp[((1<<n)-1)^(1<<i)]) res+=t[i];
    cout << res.size() << " ";
    for(char c:res) cout << c << " \n"[c==res.back()];
    return 0;
}