#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1000000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,cnt;
int ans[100005];
vector<int>e[100005];
map<int,int> mp[100005];
map<vector<int>,int> H;
set<int> st;
inline int dp(int u, int fa) {
	int x=mp[u][fa]; if (x) return x;
	vector<int> t; int len=e[u].size();//puts("1");
	for(int i=0; i<=len-1;i++) if (e[u][i]!=fa) t.push_back(dp(e[u][i],u));
	sort(t.begin(),t.end());//puts("2");
	if (!H[t]) H[t]=++cnt;//puts("3");
	return mp[u][fa]=H[t];
}
int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(e[i].size()<4)
            st.insert(dp(i,0));
    cout<<st.size()<<endl;
    return 0;
}