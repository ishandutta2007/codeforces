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
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v;
        for(int i=0;i<n;i++) if(s[i]=='W') v.push_back(i);
        if(v.empty()) cout << min(1,k)+max(0,k-1)*2 << "\n";
        else
        {
            int e=(v[0]+(n-v.back()-1));
            vector<int> a;
            for(int i=0;i<(int)v.size()-1;i++)
            {
                int l=v[i];
                int r=v[i+1];
                if(l+1<r) a.push_back(r-(l+1));
            }
            sort(a.begin(),a.end());
            int res=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='W')
                {
                    if(i>0&&s[i-1]=='W') res+=2;
                    else res++;
                }
            }
            for(int x:a)
            {
                int y=min(k,x);
                k-=y;
                res+=(2*y);
                if(y==x) res++;
            }
            res+=2*min(e,k);
            cout << res << "\n";
        }
    }
    return 0;
}