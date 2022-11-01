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
        ll n;
        int k;
        cin >> n >> k;
        string s=to_string(n);
        int len=s.size();
        ll res=stoll("1"+string(len,'0'));
        if(k==1) res=stoll(string(len+1,'1'));
        for(int i=0;i<=len;i++)
        {
            vector<bool> vis(10,0);
            int cnt=0;
            ll now=0;
            for(int j=0;j<i;j++)
            {
                int x=(s[j]-'0');
                if(vis[x]==0)
                {
                    vis[x]=1;
                    cnt++;
                }
                now=10*now+x;
            }
            if(cnt>k) continue;
            int y=(s[i]-'0');
            if(i==len) res=min(res,now);
            else if(y<9)
            {
                if(cnt<k&&vis[y+1]==0)
                {
                    vis[y+1]=1;
                    cnt++;
                }
                int z=-1;
                for(int j=y+1;j<10;j++)
                {
                    if(vis[j])
                    {
                        z=j;
                        break;
                    }
                }
                if(z==-1) continue;
                now=10*now+z;
                if(cnt<k&&vis[0]==0)
                {
                    vis[0]=1;
                    cnt++;
                }
                z=-1;
                for(int j=0;j<10;j++)
                {
                    if(vis[j])
                    {
                        z=j;
                        break;
                    }
                }
                for(int j=0;j<len-i-1;j++) now=10*now+z;
                res=min(res,now);
            }
        }
        cout << res << "\n";
    }
    return 0;
}