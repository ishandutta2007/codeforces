#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10, inf=2e18;
int si[sz];
string s1="What are you doing at the end of the world? Are you busy? Will you save us?";
string s2="What are you doing while sending \"";
string s3="\"? Are you busy? Will you send \"";
char dfs(int le, int p)
{
    if(p>=si[le]) return '.';
    if(le==0) return s1[p];
    else
    {
        if(p<s2.size()) return s2[p];
        else if(p<si[le-1]+s2.size()) return dfs(le-1, p-s2.size());
        else if(p<si[le-1]+s2.size()+s3.size()) return s3[p-si[le-1]-s2.size()];
        else if(p<si[le]-2) return dfs(le-1, p-s2.size()-s3.size()-si[le-1]);
        else if(p==si[le]-1) return '?';
        else return '"';
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    si[0]=s1.size();
    for(int a=1; a<sz; a++) si[a]=min(inf, si[a-1]*2+s2.size()+s3.size()+2);
    for(int a=0; a<q; a++)
    {
        int n, k;
        cin>>n>>k;
        cout<<dfs(n, k-1);
    }
}