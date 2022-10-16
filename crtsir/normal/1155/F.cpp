#include<bits/stdc++.h>
using namespace std;
int n,m,a[91],b[91];
vector<int>x[14],v[14];
pair<int,vector<int> >ans;
bool del[91],vis[14];
int dfs(int nw){
	vis[nw]=1;
	int ret=1;
	for(int i=0;i<v[nw].size();i++)
		if(!vis[v[nw][i]]&&del[x[nw][i]]==0)
			ret+=dfs(v[nw][i]);
	return ret;
}
bool check(){
	memset(vis,0,sizeof(vis));
	if(dfs(0)<n)return 0;
	for(int i=0;i<m;i++)
		if(!del[i]){
			del[i]=1;
			memset(vis,0,sizeof(vis));
			if(dfs(0)<n){
				del[i]=0;
				return 0;
			}
			del[i]=0;
		}
	return 1;
}
int main(){
	srand(time(NULL));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];a[i]--;b[i]--;
		v[a[i]].push_back(b[i]);
		x[a[i]].push_back(i);
		v[b[i]].push_back(a[i]);
		x[b[i]].push_back(i);
	}
	ans.first=m;
	for(int i=0;i<m;i++)ans.second.push_back(i);
	clock_t fr=clock();
	int legal=m,illegal=0;
	while(clock()-fr<1850){
		int type=rand();
		if(type%1020==0){
			memset(del,0,sizeof(del));
			legal=m;illegal=0;
			continue;
		}
		if(type%4){
			if(legal==0)continue;
			int de=rand()%legal,dl;
			for(int i=0;i<m;i++){
				if(de==0&&del[i]==0){
					de--; 
					del[i]=1,dl=i;
				}
				if(del[i]==0)
					de--;
			}legal--;illegal++;
			if(check()){
				vector<int>tmp;
				for(int i=0;i<m;i++)
					if(del[i]==0)
						tmp.push_back(i);
				ans=min(ans,make_pair(legal,tmp));
			}else{
				del[dl]=0;
				legal++;
				illegal--;
			}
		}else{
			if(illegal==0)continue;
			int ad=rand()%illegal;
			for(int i=0;i<m;i++){
				if(ad==0&&del[i]==1){
					ad--;
					del[i]=0;
				}
				if(del[i]==1)
					ad--;
			}
			legal++;illegal--;
		}
	}
	cout<<ans.first<<endl;
	for(int i=0;i<ans.first;i++)
		cout<<a[ans.second[i]]+1<<' '<<b[ans.second[i]]+1<<endl;
}