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
        map<char,int> m;
        for(char c:s) m[c]++;
        char x='R';
        for(auto [a,b]:m) if(b>m[x]) x=a;
        char y='$';
        if(x=='R') y='P';
        else if(x=='S') y='R';
        else if(x=='P') y='S';
        cout << string(n,y) << "\n";
    }
    return 0;
}