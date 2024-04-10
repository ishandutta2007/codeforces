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
        string a,b;
        cin >> a >> b;
        vector<int> one(26,0);
        for(char c:a) one[c-'a']++;
        vector<int> two(26,0);
        for(char c:b) two[c-'a']++;
        bool ok=1;
        for(int i=0;i<26;i++)
        {
            if(one[i]<two[i]) ok=0;
            one[i]-=two[i];
            if((one[i]%k)!=0) ok=0;
            one[i+1]+=one[i];
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}