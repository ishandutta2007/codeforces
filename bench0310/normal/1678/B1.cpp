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
        auto go=[&](string s)->array<int,2>
        {
            vector<int> v;
            int l=0;
            while(l<n)
            {
                int r=l;
                while(r+1<n&&s[r+1]==s[l]) r++;
                v.push_back(r-l+1);
                l=r+1;
            }
            int sz=v.size();
            int res=0;
            int opt=sz;
            l=0;
            while(l<sz)
            {
                if((v[l]%2)==0)
                {
                    l++;
                    continue;
                }
                int r=l+1;
                while((v[r]%2)==0) r++;
                res+=(r-l);
                for(int i=l+(l==0);i<=r-(r==sz-1);i++)
                {
                    if(v[i]<=2)
                    {
                        opt-=2;
                        v[i+1]+=2;
                    }
                }
                if(l==0&&v[0]==1&&v[1]>2) opt--;
                if(r==sz-1&&v[r]==1) opt--;
                l=r+1;
            }
            return {res,opt};
        };
        string s;
        cin >> s;
        auto one=go(s);
        s[0]^=('0'^'1');
        auto two=go(s);
        two[0]++;
        auto res=min(one,two);
        cout << res[0] << "\n";
    }
    return 0;
}