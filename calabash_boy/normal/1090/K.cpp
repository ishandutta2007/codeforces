/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 18:20:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],tot,cnt;
string s,t;
set<char> st;
map<string,int> mp;
map<P,int> group;
vector<int> sss[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s; cin>>t;
        st.clear();
        for(int i=0;i<(int)t.size();i++) st.insert(t[i]);
        int y=0;
        for(auto ch:st) y=(1LL*y*19260817+ch-'a'+1)%MOD;
        int pos=-1;
        for(int i=(int)s.size()-1;i>=0;i--)
        {
            if(!st.count(s[i]))
            {
                pos=i;
                break;
            }
        }
        int x;
        if(pos==-1) x=0; else 
        {
            string ss=s.substr(0,pos+1);
            if(mp.find(ss)==mp.end())
            {
                mp[ss]=++tot;x=tot;
            }
            else x=mp[ss];
        }
        if(group.find(P(x,y))==group.end()) group[P(x,y)]=++cnt;
        sss[group[P(x,y)]].push_back(i);
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        int sz=(int)sss[i].size();
        printf("%d ",sz);
        for(int j=0;j<sz;j++) printf("%d%c",sss[i][j],j==sz-1?'\n':' ');
    }
    return 0;
}