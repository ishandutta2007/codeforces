#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int ans1[1000002];
int ans2[1000002];
int ok[1000002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        int siz = n * m;
        for(int i=0;i<=siz+1;i++) ans1[i] = ans2[i] = 0;
        for(int i=0;i<=m+1;i++) ok[i] = 0;
        for(int i=1;i<=siz;i++)
        {
            if(s[i-1] == '1' && ok[i%m] == 0)
            {
                ok[i%m] = 1;
                ans1[i]++;
            }
        }
        
        for(int i=1;i<=siz;i++) ans1[i] += ans1[i-1];
        
        int cnt = m-1;
        for(int i=1;i<=siz;i++)
        {
            if(s[i-1] == '1') cnt = 0;
            else cnt++;
            
            if(cnt >= m)
            {
                ans2[i]--;
            }
        }
        
        for(int i=m;i<=siz;i++) ans2[i] += ans2[i-m];
        
        for(int i=1;i<=siz;i++)
        {
            int k = (i-1)/m + 1;
            cout << k + ans1[i] + ans2[i] << " ";
        }
        cout << "\n";
    }
}