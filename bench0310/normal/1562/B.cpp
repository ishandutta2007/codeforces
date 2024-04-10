#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=99;
    vector<bool> prime(N+1,1);
    prime[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(!prime[i]) continue;
        for(int j=i*i;j<=N;j+=i) prime[j]=0;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        array<int,2> res=[&]()->array<int,2>
        {
            for(char c:s) if(!prime[c-'0']) return {1,c-'0'};
            for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(!prime[10*(s[i]-'0')+(s[j]-'0')]) return {2,10*(s[i]-'0')+(s[j]-'0')};
        }();
        cout << res[0] << "\n" << res[1] << "\n";
    }
    return 0;
}