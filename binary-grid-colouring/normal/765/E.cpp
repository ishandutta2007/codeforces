#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
vector<int> G[N];
int root;
int dfs(int cur, int fa)
{
    set<int>s;
    for(auto v: G[cur])
    {
    	if(v!=fa){
    		int tmp = dfs(v,cur);
    		if(tmp==-1)return -1;
    		else s.insert(tmp+1);
		}
	}
	if(s.size() == 0) return 0;
	else if(s.size() == 1) return *s.begin();
	else if(s.size() == 2 && fa == 0) return *s.begin()+*s.rbegin();
	else if(s.size()==2 && fa!=0)
	{
		root = cur;
		return -1;
	}
	else if(s.size()>2)return -1;
}
int main()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i<n-1; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
   int ans= dfs(1,0);
   if(ans==-1 && root) ans = dfs(root,0);
   while(ans%2==0){
   	ans/=2;
   }
   return 0*printf("%d\n",ans);
}
/*
6
1 2
2 3
2 4
4 5
1 6

3

11
11 9
6 7
7 1
8 11
5 6
3 5
9 3
10 8
2 4
4 10

5
*/