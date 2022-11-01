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
        int n,k;
        string s;
        cin >> n >> k >> s;
        s="$"+s;
        array<int,26> c;
        c.fill(0);
        for(int i=1;i<=n;i++) c[s[i]-'a']=(c[s[i]-'a']+1)%k;
        bool ok=1;
        for(int x:c) ok&=(x==0);
        if(ok)
        {
            cout << s.substr(1) << "\n";
            continue;
        }
        bool res=0;
        for(int i=n-1;i>=0;i--)
        {
            c[s[i+1]-'a']--;
            if(c[s[i+1]-'a']==-1) c[s[i+1]-'a']=k-1;
            for(int j=(s[i+1]-'a'+1);j<26;j++)
            {
                int req=0;
                c[j]=(c[j]+1)%k;
                for(int a=0;a<26;a++) req+=((k-c[a])%k);
                int cnt=n-i-1;
                if(req<=cnt&&((cnt-req)%k)==0)
                {
                    for(int a=1;a<=i;a++) cout << s[a];
                    array<int,26> now;
                    now.fill(0);
                    for(int a=0;a<26;a++) now[a]=((k-c[a])%k);
                    now[0]+=(cnt-req);
                    cout << (char)(j+'a');
                    for(int a=0;a<26;a++) for(int b=0;b<now[a];b++) cout << (char)(a+'a');
                    cout << "\n";
                    res=1;
                }
                if(res==1) break;
                c[j]--;
                if(c[j]==-1) c[j]=k-1;
            }
            if(res==1) break;
        }
        if(res==0) cout << "-1\n";
    }
    return 0;
}