#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    int a,b;
    cin >> a >> b;
    vector<int> one(n);
    one[0]=((s[0]-'0')%a);
    for(int i=1;i<n;i++) one[i]=(10*one[i-1]+(s[i]-'0'))%a;
    vector<int> two(n);
    two[n-1]=((s[n-1]-'0')%b);
    int p=1;
    for(int i=n-2;i>=0;i--)
    {
        p=(10*p)%b;
        two[i]=(p*(s[i]-'0')+two[i+1])%b;
    }
    int res=-1;
    for(int i=0;i<n-1;i++) if(one[i]==0&&two[i+1]==0&&s[i+1]!='0') res=i;
    if(res!=-1)
    {
        cout << "YES\n";
        cout << s.substr(0,res+1) << "\n";
        cout << s.substr(res+1,n-(res+1)) << "\n";
    }
    else cout << "NO\n";
    return 0;
}