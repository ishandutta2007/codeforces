#include<bits/stdc++.h>
using namespace std;
vector<string> a;
vector<vector<pair<int,int> > > s,t;
const int dx[]={1,0},dy[]={0,1};
int main(){
	int n,m; scanf("%d%d",&n,&m); a.resize(n);
	for(int i=0;i<n;++i)
		cin>>a[i];
	int ans=2;
	s.resize(n+m); t.resize(n+m);
	s[0].push_back(make_pair(0,0));
	for(int i=0;i<=n+m-3;++i){
		sort(s[i].begin(),s[i].end());
		s[i].erase(unique(s[i].begin(),s[i].end()),s[i].end());
		for(auto j:s[i]){
			int x=j.first,y=j.second;	
			for(int asp=0;asp<2;++asp){
				int x1=x+dx[asp],y1=y+dy[asp];
				if(x1<0||x1>=n||y1<0||y1>=m||a[x1][y1]=='#') continue;
				s[i+1].push_back(make_pair(x1,y1));
			}
		}
	}
	t[n+m-2].push_back(make_pair(n-1,m-1));
	for(int i=n+m-2;i>=1;--i){
		sort(t[i].begin(),t[i].end());
		t[i].erase(unique(t[i].begin(),t[i].end()),t[i].end());
		for(auto j:t[i]){
			int x=j.first,y=j.second;
			for(int asp=0;asp<2;++asp){
				int x1=x-dx[asp],y1=y-dy[asp];
				if(x1<0||x1>=n||y1<0||y1>=m||a[x1][y1]=='#') continue;
				t[i-1].push_back(make_pair(x1,y1));
			}
		}
	}
	for(int i=1;i<=n+m-3;++i){
		int cnt=0;
		for(auto j:s[i]){
			auto it=lower_bound(t[i].begin(),t[i].end(),j);
			if(it!=t[i].end()&&(*it)==j) ++cnt;
		}
		ans=min(ans,cnt);
	}
			
	printf("%d\n",ans);
	return 0;
}