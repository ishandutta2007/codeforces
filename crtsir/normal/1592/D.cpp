#include<bits/stdc++.h>
using namespace std;
int n,a,b;
vector<pair<int,int> >ed;
vector<int>v[1003];
bool h[1003][1003];
void print(vector<pair<int,int> >qaq){
	vector<int>v;
	for(int i=0;i<qaq.size();i++)
		v.push_back(qaq[i].first),
		v.push_back(qaq[i].second);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	cout<<"? "<<v.size()<<' ';
	for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;
	fflush(stdout);
}
vector<pair<int,int> >canbe;
int dfs(int x,int cnt,int p){
	for(int i=0;i<v[x].size();i++)
		if(h[x][v[x][i]]&&v[x][i]!=p){
			if(cnt)cnt--,canbe.push_back(make_pair(min(x,v[x][i]),max(x,v[x][i])));
			if(cnt)cnt=dfs(v[x][i],cnt,x);
		}
	return cnt;
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		ed.push_back(make_pair(min(a,b),max(a,b)));
		v[a].push_back(b);
		v[b].push_back(a);
		h[a][b]=1;h[b][a]=1;
	}
	int nw=0;
	print(ed);
	scanf("%d",&nw);canbe=ed;
	int lst=nw;
	while(ed.size()>1){canbe.clear();
		int QAQ=ed.size()/2;
		for(int i=0;i<ed.size();i++){
			if(QAQ)QAQ=dfs(ed[i].first,QAQ,-1);
			if(QAQ)QAQ=dfs(ed[i].second,QAQ,-1);
		}
		print(canbe);
		scanf("%d",&nw);
		if(lst==nw)
			ed=canbe;
		else{
			vector<pair<int,int> >tmp=canbe;
			canbe.clear();
			for(int j=0;j<ed.size();j++){
				bool ok=1;
				for(int k=0;k<tmp.size();k++)
					if(ed[j]==tmp[k])
						ok=0;
				if(ok)canbe.push_back(ed[j]);
			}
			ed=canbe;
		}
		memset(h,0,sizeof(h));
		for(int i=0;i<ed.size();i++)
			h[ed[i].first][ed[i].second]=1,
			h[ed[i].second][ed[i].first]=1;
	}cout<<"! "<<ed[0].first<<' '<<ed[0].second;fflush(stdout);
}