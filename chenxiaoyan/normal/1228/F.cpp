#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=17;
int n;
vector<int> nei[1<<N];
set<int> son[1<<N];
void dfs(int x=1,int fa=0){
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		son[x].insert(y);
		dfs(y,x);
	}
}
pair<int,int> f[1<<N];
void calc_f(int x){
	if(son[x].size()==0)f[x]=mp(0,1);
	else if(son[x].size()==1)f[x]=f[*son[x].begin()]==mp(0,1)?mp(x,2):mp(-1,-1);
	else if(son[x].size()==2){
		pair<int,int> x1=f[*son[x].begin()],x2=f[*++son[x].begin()];
		if(x1>x2)swap(x1,x2);
		if(!x1.X&&!x2.X)f[x]=x1.Y==x2.Y?mp(0,x1.Y+1):mp(-1,-1);
		else if(!x1.X&&x2.X>0)f[x]=x1.Y==x2.Y?mp(x2.X,x1.Y+1):mp(-1,-1);
		else f[x]=mp(-1,-1);
	}
	else if(son[x].size()==3){
		pair<int,int> x1=f[*son[x].begin()],x2=f[*++son[x].begin()],x3=f[*++ ++son[x].begin()];
		if(x1>x2)swap(x1,x2);if(x2>x3)swap(x2,x3);if(x1>x2)swap(x1,x2);
		if(!x1.X&&!x2.X&&!x3.X)f[x]=x1.Y==x2.Y&&x2.Y+1==x3.Y?mp(x,x3.Y+1):mp(-1,-1);
		else f[x]=mp(-1,-1);
	}
	else f[x]=mp(-1,-1);
//	printf("f[%d]=(%d,%d)\n",x,f[x].X,f[x].Y);
}
void dp(int x=1,int fa=0){
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dp(y,x);
	}
	calc_f(x);
}
vector<int> ans;
void dfs0(int x=1,int fa=0){
	if(f[x].X>0)ans.pb(f[x].X);
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		son[x].erase(y);son[y].insert(x);calc_f(x);calc_f(y);
		dfs0(y,x);
		son[x].insert(y);son[y].erase(x);calc_f(y);calc_f(x);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=(1<<n)-3;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	dp();
	dfs0();
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}
/*1
4
1 2
1 3
2 4
2 5
3 6
3 13
3 14
4 7
4 8
5 9
5 10
6 11
6 12
*/
/*2
2
1 2
*/
/*3
3
1 2
2 3
3 4
4 5
5 6
*/