#include<bits/stdc++.h>

using namespace std;

vector<int> p_function(const string& s)
{
    int n = s.size();
    vector<int> ans(n, 0);
    for(int i = 1; i < n; i++)
    {
        int k = ans[i - 1];
        while(k != 0 && s[k] != s[i])
            k = ans[k - 1];
        if(s[k] == s[i])
            k++;
        ans[i] = k;       
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> lens(n + 1);
    for(int i = 0; i <= n; i++)
        lens[i] = to_string(i).size();
    vector<int> dp(n + 1, int(1e9));
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        //cerr << dp[i] << endl;
        vector<int> pf = p_function(s.substr(i, n - i));
        for(int j = i + 1; j <= n; j++)
        {                         
            int len = j - i;
            int p = (len % (len - pf[len - 1]) == 0 ? len - pf[len - 1] : len);                 
            int add = p + lens[len / p];
            dp[j] = min(dp[j], dp[i] + add);
        }
    }
    cout << dp[n] << endl;
}