#include<bits/stdc++.h>
#define int long long
#define _to sn[i][nw]
const int N=205005;
using namespace std;

int sn[26][N],n;
int fa[N],sm[N],cnt;
string s[N],t;

void insert(string s){
	int nw=0;
	for(auto x:s){
		if(!sn[x-'a'][nw])sn[x-'a'][nw]=++cnt;
		nw=sn[x-'a'][nw];
	}
	++sm[nw];
}
void build(){
	queue<int> q;
	for(int i=0;i<26;i++)
		if(sn[i][0])q.push(sn[i][0]);
	while(q.size()){
		int nw=q.front();q.pop();
		for(int i=0;i<26;i++)
			if(_to)
				fa[_to]=sn[i][fa[nw]],sm[_to]+=sm[fa[_to]],q.push(_to);
			else _to=sn[i][fa[nw]];
	}
}
vector<int>calc(){
	vector<int>ans(t.size());
	int nw=0;
	for(int i=0;i<t.size();i++)
		nw=sn[t[i]-'a'][nw],ans[i]=sm[nw];
	return ans;
}
void clear(){
	memset(sn,0,sizeof(sn));
	memset(fa,0,sizeof(fa));
	memset(sm,0,sizeof(sm));
	cnt=0;
}
vector<int>solve(){
	clear();
	for(int i=1;i<=n;i++)
		insert(s[i]);
	build();
	return calc();
} 
void rev(){
	reverse(t.begin(),t.end());
	for(int i=1;i<=n;i++)reverse(s[i].begin(),s[i].end());
}
main(){
	cin>>t>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	auto a=solve();rev();auto b=solve();
	int ans=0;
	for(int i=0;i<t.size()-1;i++)
		ans=ans+a[i]*b[t.size()-i-2];
	cout<<ans<<endl;
}