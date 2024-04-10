#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,k;
string a;
vector<int>v[30];
int st[30];

int sol[400005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        v[a[i]-'a'].push_back(i);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(st[j]!=v[j].size())
            {
                st[j]++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        sol[i]=-1;
    for(int i=0;i<26;i++)
        for(int j=st[i];j<v[i].size();j++)
            sol[v[i][j]]=i+'a';
    for(int i=0;i<n;i++)
        if(sol[i]!=-1)
            cout<<char(sol[i]);
    cout<<"\n";
    return 0;
}
/**

**/