#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
vector<vector<int> > solve(vector<int> a){
	vector<vector<int> > stk;
	vector<int> val;
	for(int i=0;i<a.size();++i){
		int p=lower_bound(val.begin(),val.end(),a[i])-val.begin();
		if(p==val.size()) stk.push_back(vector<int>()),val.push_back(0);
		val[p]=a[i]; stk[p].push_back(a[i]);
	}
	return stk;
}
vector<int> erase(vector<int> a,vector<int> b){
	int p=0; vector<int> c;
	for(int i=0;i<a.size();++i){
		if(p<b.size()&&a[i]==b[p]) ++p;
		else c.push_back(a[i]);
	}
	return c;
}
bool cmp(int x,int y){ return x>y; }
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		vector<vector<int> > ans;
		while(!a.empty()){
			int k=1; for(;k*(k+1)/2<a.size();++k);
			vector<vector<int> > b=solve(a);
			vector<int> c; c.push_back(b[(int)b.size()-1][0]);
			for(int i=(int)b.size()-2;i>=0;--i)
				c.push_back(*lower_bound(b[i].begin(),b[i].end(),c.back(),cmp));
			reverse(c.begin(),c.end());
			if(c.size()>=k){
				ans.push_back(c);
				a=erase(a,c);
			}
			else{
				for(int i=0;i<b.size();++i)
					ans.push_back(b[i]);
				break;
			}
		}
		printf("%d\n",int(ans.size()));
		for(auto x:ans){
			printf("%d ",int(x.size()));
			for(auto y:x)
				printf("%d ",y);
			puts("");
		}
	}
	return 0;
}