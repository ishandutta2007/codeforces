#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
unordered_map<int,vector<int> > mp;
vector<int> pos;
vector<int> g[N];
int lst[N];
bool check(int m){
	if(m==0) return true;
	static int left[N],right[N];
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=m;++i){
		left[i]=pos[i-1];
		right[i]=pos[(int)pos.size()-m+i-1];
		g[i].clear();
	}
	int cc=0;
	for(auto t:mp){
		int cnt0=0,cnt1=0;
		for(auto x:t.second){
			if(x>=left[m]&&x<=right[1]){
				cnt0=cnt1=m;
			}else if(x<left[m]){
				int c=lst[x];
				cnt0=max(cnt0,c);	
			}else if(x>right[1]){
				int c=(int)pos.size()-lst[x];
				cnt1=max(cnt1,c);
			}
		}
		if(cnt0+cnt1>=m){
			g[1].push_back(m);
		}else{
			int pos=m-cnt1+1;
			if(pos>m) pos=1;
			g[pos].push_back(cnt0+cnt1);
		}
	}
	int cnt=0;
	for(int t=0;t<2;++t){
		for(int i=1;i<=m;++i){
			for(auto x:g[i]) q.push(x+cnt);
			g[i].clear();
			while(!q.empty()&&q.top()<=cnt) q.pop();
			if(!q.empty()){
				g[i].push_back(q.top()-cnt);
				q.pop();
			}
			++cnt;
		}
	}
	for(int i=1;i<=m;++i)
		if(g[i].empty()) return false;
	return true;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		mp.clear(); pos.clear();
		int last=0;
		for(int i=1;i<=n;++i){
			int x; scanf("%d",&x);
			if(x>0){
				mp[x].push_back(i);
				lst[i]=last;
			}else{
				pos.push_back(i);
				++last;
			}
		}
		int left=0,right=(int)pos.size()/2;
		while(left<right){
			int mid=left+right+1>>1;
			if(check(mid)) left=mid;
			else right=mid-1;
		}
		printf("%d\n",left);
	}
	return 0;
}