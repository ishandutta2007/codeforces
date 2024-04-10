#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1<<17|5;
pair<int,int> h[MAX_N];
vector<int> son[MAX_N],ans;
bool cmp(int x,int y){ return h[x]<h[y]; }
void updata(int x,vector<int> a){
	sort(a.begin(),a.end(),cmp);
	int sum=0;
	for(int i=0;i<a.size();++i){
		if(h[a[i]].first==-1){
			h[x]=make_pair(-1,0); 
			return;
		}
		if(h[a[i]].second>0){
			if(sum>0){
				h[x]=make_pair(-1,0);
				return;
			}
			sum+=h[a[i]].second;
		}
	}
	if(a.size()==0){
		h[x]=make_pair(1,0);
	}else if(a.size()==1&&h[a[0]].first==1){
		h[x]=make_pair(2,x);
	}else if(a.size()==2&&h[a[0]].first==h[a[1]].first){
		h[x]=make_pair(h[a[0]].first+1,sum);
	}else if(a.size()==3&&h[a[0]].first==h[a[1]].first
				&&h[a[0]].first+1==h[a[2]].first&&sum==0){
		h[x]=make_pair(h[a[2]].first+1,x);
	}else h[x]=make_pair(-1,0);
}

			
void dfs1(int x,int pre){
	for(int i=0;i<son[x].size();++i){
		if(son[x][i]!=pre)
			dfs1(son[x][i],x);
	}
	sort(son[x].begin(),son[x].end(),cmp);
	vector<int> b=son[x]; 
	if(pre!=0) b.erase(find(b.begin(),b.end(),pre));
	updata(x,b);
}
void dfs2(int x,int pre){
	pair<int,int> rh=h[x];
	updata(x,son[x]);
	if(h[x].first!=-1) 
		ans.push_back(h[x].second);
	for(int i=0;i<son[x].size();++i)
		if(son[x][i]!=pre){
			vector<int> b=son[x];
			b.erase(find(b.begin(),b.end(),son[x][i]));
			updata(x,b);
			dfs2(son[x][i],x);
		}
	h[x]=rh;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=(1<<n)-3;++i){
		int x,y; scanf("%d%d",&x,&y);
		son[x].push_back(y);
		son[y].push_back(x);
	}
	for(int i=1;i<=(1<<n)-2;++i)
		if(son[i].size()>4){
			puts("0");
			return 0;
		}
	dfs1(1,0);
	dfs2(1,0);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x);
	return 0;
}