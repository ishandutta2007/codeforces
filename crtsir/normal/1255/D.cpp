#include<bits/stdc++.h>
using namespace std;
string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
void solve(){
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	char c[n][m],ans[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j],cnt+=(c[i][j]=='R');
	vector<pair<int,int> >v;
	if(m>1){ 
		v.push_back(make_pair(0,0));
		v.push_back(make_pair(0,1));
		for(int i=2;i<n*m;i++){
			pair<int,int>last=v.back();
			if(v[v.size()-1].second!=v[v.size()-2].second&&(last.second==m-1||last.second==0))last.first++;
			else last.second+=(i/m+1)%2*2-1;
			v.push_back(last);
		}
	}else
		for(int i=0;i<n;i++)
			v.push_back(make_pair(i,0));
	int cc=0,maxn=cnt/k+1,ct;
	ct=cnt-maxn*k+k;
	cnt=0; 
	for(int i=0;i<v.size();i++)
	{
		if(ct==0)maxn--,ct=-1;
		cnt+=(c[v[i].first][v[i].second]=='R'),
		ans[v[i].first][v[i].second]=s[cc];
		if(cnt==maxn&&cc!=k-1)cnt=0,cc++,ct--;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<ans[i][j];
		cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}