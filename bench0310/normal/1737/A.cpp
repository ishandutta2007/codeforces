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
        vector<int> c(26,0);
        for(char a:s) c[a-'a']++;
        for(int i=0;i<k;i++)
        {
            int p=0;
            while(p<n/k&&c[p]>0) p++;
            cout << char(p+'a');
            for(int j=0;j<p;j++) c[j]--;
        }
        cout << "\n";
    }
    return 0;
}