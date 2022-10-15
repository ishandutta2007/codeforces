#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
const int MOD=1000000007;

string s;
int p;

int read()
{
    int sol=0;
    while('0'<=s[p] && s[p]<='9')
    {
        sol=10*sol+s[p]-'0';
        p++;
    }
    return sol;
}

map<double,int>mp;

vector<double>v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        p=1;
        int a=read();p++;
        int b=read();p+=2;
        int c=read();
        double val=(double)(a+b)/c;
        mp[val]++;
        v.push_back(val);
    }
    for(int i=0;i<n;i++)
        cout<<mp[v[i]]<<" ";
    cout<<"\n";
    return 0;
}