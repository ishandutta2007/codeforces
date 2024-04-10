/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=1000;
int n; 
pair<int,int> a[N+1];
vector<int> nei[N+1];
vector<int> nums_x,nums_y;
void discrete(){
	sort(nums_x.begin(),nums_x.end());
	nums_x.resize(unique(nums_x.begin(),nums_x.end())-nums_x.begin());
	sort(nums_y.begin(),nums_y.end());
	nums_y.resize(unique(nums_y.begin(),nums_y.end())-nums_y.begin());
}
int cnt,cid[N+1];
void dfs(int x){
	cid[x]=cnt;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(!cid[y])dfs(y);
	}
}
vector<pair<int,int> > row[N],col[N];
int now_r[N],now_c[N];
bool chk(int x){
	for(int i=1;i<=n;i++)nei[i].clear();
	for(int i=0;i<nums_x.size();i++){
		for(int j=0;j+1<row[i].size();j++)
			if(abs(row[i][j].X-row[i][j+1].X)<=x)
				nei[row[i][j].Y].pb(row[i][j+1].Y),nei[row[i][j+1].Y].pb(row[i][j].Y);
	}
	for(int i=0;i<nums_y.size();i++){
		for(int j=0;j+1<col[i].size();j++)
			if(abs(col[i][j].X-col[i][j+1].X)<=x)
				nei[col[i][j].Y].pb(col[i][j+1].Y),nei[col[i][j+1].Y].pb(col[i][j].Y);
	}
	cnt=0,memset(cid,0,sizeof(cid));
	for(int i=1;i<=n;i++)if(!cid[i])cnt++,dfs(i);
	if(cnt==1)return true;
	if(cnt<=2){
		for(int i=0;i<nums_x.size();i++){
			for(int j=0;j+1<row[i].size();j++)
				if(cid[row[i][j].Y]!=cid[row[i][j+1].Y]&&abs(row[i][j].X-row[i][j+1].X)+1>>1<=x)return true;
		}
		for(int i=0;i<nums_y.size();i++){
			for(int j=0;j+1<col[i].size();j++)
				if(cid[col[i][j].Y]!=cid[col[i][j+1].Y]&&abs(col[i][j].X-col[i][j+1].X)+1>>1<=x)return true;
		}
	}
	memset(now_r,0,sizeof(now_r)),memset(now_c,0,sizeof(now_c));
	if(cnt<=4)for(int i=0;i<nums_x.size();i++)for(int j=0;j<nums_y.size();j++){
		int xx=nums_x[i],yy=nums_y[j];
		while(now_r[i]<row[i].size()&&row[i][now_r[i]].X<yy)now_r[i]++;
		while(now_c[j]<col[j].size()&&col[j][now_c[j]].X<xx)now_c[j]++;
		if(now_r[i]<row[i].size()&&row[i][now_r[i]].X==yy)continue;
		set<int> st;
		if(now_r[i]&&abs(row[i][now_r[i]-1].X-yy)<=x)st.insert(cid[row[i][now_r[i]-1].Y]);
		if(now_r[i]<row[i].size()&&abs(row[i][now_r[i]].X-yy)<=x)st.insert(cid[row[i][now_r[i]].Y]);
		if(now_c[j]&&abs(col[j][now_c[j]-1].X-xx)<=x)st.insert(cid[col[j][now_c[j]-1].Y]);
		if(now_c[j]<col[j].size()&&abs(col[j][now_c[j]].X-xx)<=x)st.insert(cid[col[j][now_c[j]].Y]);
		if(st.size()==cnt&&*st.begin()==1&&*--st.end()==cnt)return true;
	}
	return false;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].X>>a[i].Y,nums_x.pb(a[i].X),nums_y.pb(a[i].Y);
	discrete();
	for(int i=1;i<=n;i++){
		row[lower_bound(nums_x.begin(),nums_x.end(),a[i].X)-nums_x.begin()].pb(mp(a[i].Y,i));
		col[lower_bound(nums_y.begin(),nums_y.end(),a[i].Y)-nums_y.begin()].pb(mp(a[i].X,i));
	}
	for(int i=0;i<nums_x.size();i++)sort(row[i].begin(),row[i].end());
	for(int i=0;i<nums_y.size();i++)sort(col[i].begin(),col[i].end());
	int ans=4e9;
	for(int i=32;~i;i--)if(ans-(1ll<<i)>=0&&chk(ans-(1ll<<i)))ans-=1ll<<i;
	cout<<(ans==4e9?-1:ans);
	return 0;
}