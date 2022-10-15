#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
unordered_map<int, int> cnt;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        ll sol=0;
        int n;
        cin>>n;
        cnt.rehash(2*n);
        for (int it=1;it<=n;it++)
        {
                string s;
                cin>>s;
                int odd=0;
                for (auto &ch : s)
                        odd^=(1<<(ch-'a'));
                for (int x=0;x<26;x++)
                        sol+=cnt[odd^(1<<x)];
                sol+=cnt[odd]++;
        }
        cout<<sol<<"\n";

}