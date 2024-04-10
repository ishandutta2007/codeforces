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
        string s;
        cin >> s;
        int n=s.size();
        int sum=0;
        for(char c:s) sum+=(c-'a'+1);
        if((n%2)==0) cout << "Alice " << sum << "\n";
        else if(n>=3) cout << "Alice " << sum-2*(min(s[0],s[n-1])-'a'+1) << "\n";
        else cout << "Bob " << sum << "\n";
    }
    return 0;
}