#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        bool F = false;
        for(int i=0;i<26;i++)
        {
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                if(s[j] - 'a' == i) flag = false;
            }

            if(flag)
            {
                cout << (char)('a' + i) << "\n";
                F = true;
                break;
            }
        }

        if(F) continue;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                bool flag = true;
                for(int k=1;k<n;k++)
                {
                    if(s[k-1] - 'a' == i && s[k] - 'a' == j) flag = false;
                }

                if(flag)
                {
                    cout << (char)(i + 'a') << (char)(j + 'a') << "\n";
                    F = true;
                    break;
                }
            }
            if(F) break;
        }

        if(F) continue;

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    bool flag = true;
                    for(int p=2;p<n;p++)
                    {
                        if(s[p-2] - 'a' == i && s[p-1] - 'a' == j && s[p] - 'a' == k) flag = false;
                    }

                    if(flag)
                    {
                        F = true;
                        cout << (char)(i+'a') << (char)(j+'a') << (char)(k+'a') << "\n";
                        break;
                    }
                }
                if(F) break;
            }
            if(F) break;
        }
    }
}