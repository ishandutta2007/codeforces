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
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        int res=0;
        for(int i=0;i<5;i++)        
        {
            vector<int> v(n,0);
            for(int j=0;j<n;j++)
            {
                for(char a:s[j])
                {
                    if(a==(i+'a')) v[j]++;
                    else v[j]--;
                }
            }
            sort(v.begin(),v.end(),greater<>());
            int now=0;
            int x=0;
            for(int c:v)
            {
                if(x+c>0)
                {
                    now++;
                    x+=c;
                }
            }
            res=max(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}