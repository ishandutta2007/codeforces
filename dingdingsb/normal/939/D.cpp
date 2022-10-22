#include<bits/stdc++.h>
using namespace std;
const int N=100000+100;
int n,fa[N];
char a[N],b[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main(){
	cin>>n;
	cin>>a+1;
	cin>>b+1;
	for(int i='a';i<='z';i++)fa[i]=i;
	for(int i=1;i<=n;i++)
		fa[find(a[i])]=find(b[i]);
	vector<pair<char,char> >ans;
	for(int i='a';i<='z';i++)
		if(find(i)!=i)
			ans.push_back(make_pair(i,find(i)));
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%c %c\n",ans[i].first,ans[i].second);
}