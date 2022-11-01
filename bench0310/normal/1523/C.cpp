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
        vector<int> now;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            if(a==1) now.push_back(1);
            else
            {
                while(now.back()!=a-1) now.pop_back();
                now.back()++;
            }
            for(int j=0;j<(int)now.size();j++) cout << now[j] << ".\n"[j==(int)now.size()-1];
        }
    }
    return 0;
}