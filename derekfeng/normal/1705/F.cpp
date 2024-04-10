#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,s[1005],d;
int ask(){
	for(int i=0;i<n;i++)putchar(s[i]?'T':'F');puts("");fflush(stdout);
	int x;scanf("%d",&x);if(x==n)exit(0);fflush(stdout);return x;
}
int qry(vector<int>v){
	for(auto x:v)s[x]^=1;
	int res=ask();
	for(auto x:v)s[x]^=1;
	return ((int)v.size()+res-d)/2;
}
vector<int>calc(vector<int>v){
	int n=v.size();
	vector<int>ans;ans.resize(n);
	if(v.size()<=2){
		for(int i=0;i<n;i++)ans[i]=qry({v[i]});
		return ans;
	}
	vector<int>a,b;
	for(int i=0;i<n;i+=4){
		vector<int>vv,pos;
		for(int j=i,k=0;j<n&&k<4;j++,k++)
			vv.push_back(v[j]),pos.push_back(j);
		int tmp=qry(vv);
		if(tmp==0){for(auto x:pos)ans[x]=0;continue;}
		if(tmp==vv.size()){for(auto x:pos)ans[x]=1;continue;}
		if(vv.size()==2){a.push_back(pos[0]),b.push_back(pos[1]);continue;}
		if(vv.size()==3){
			int t=0;
			for(int j=0;j<2;j++){
				int x=qry({vv[j]});
				ans[pos[j]]=x,t+=x;
			}
			ans[pos[2]]=tmp-t;
			continue;
		}
		int cur=qry({vv[0],vv[1]});
		if(cur==0)ans[pos[0]]=ans[pos[1]]=0;
		if(cur==1)a.push_back(pos[0]),b.push_back(pos[1]);
		if(cur==2)ans[pos[0]]=ans[pos[1]]=1;
		tmp-=cur;
		if(tmp==0)ans[pos[2]]=ans[pos[3]]=0;
		if(tmp==1)a.push_back(pos[2]),b.push_back(pos[3]);
		if(tmp==2)ans[pos[2]]=ans[pos[3]]=1;
	}
	vector<int>h;
	for(auto x:a)h.push_back(v[x]);
	vector<int>C=calc(h);
	for(int i=0;i<a.size();i++)
		ans[a[i]]=C[i],ans[b[i]]=C[i]^1;
	return ans;
}
int main(){
	scanf("%d",&n);vector<int>v;
	for(int i=0;i<n;i++)s[i]=rng()&1,v.push_back(i);
	d=ask();vector<int>ans=calc(v);
	for(int i=0;i<n;i++)if(ans[i])s[i]^=1;ask();
}