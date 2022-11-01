#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string,int> m;
    for(int i=0;i+1<n;i++) m[s.substr(i,2)]++;
    string res="";
    m[""]=0;
    for(auto [t,c]:m) if(c>m[res]) res=t;
    cout << res << "\n";
    return 0;
}