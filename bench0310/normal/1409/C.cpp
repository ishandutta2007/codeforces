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
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> res={x,y};
        for(int i=0;i<n-2;i++) res.push_back(res.back()+(y-x));
        for(int i=1;i<=y-x;i++)
        {
            if(((y-x)%i)!=0) continue;
            if(((y-x)/i)-1>n-2) continue;
            vector<int> tmp={x};
            while(tmp.back()<y) tmp.push_back(tmp.back()+i);
            int cnt=n-tmp.size();
            vector<int> now;
            for(int j=1;cnt>0&&x-j*i>0;j++)
            {
                now.push_back(x-j*i);
                cnt--;
            }
            reverse(now.begin(),now.end());
            for(int z:tmp) now.push_back(z);
            while(cnt--) now.push_back(now.back()+i);
            if(now.back()<res.back()) res=now;
        }
        for(int a:res) cout << a << " ";
        cout << "\n";
    }
    return 0;
}