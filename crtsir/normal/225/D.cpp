#include<bits/stdc++.h>
using namespace std;
int n,m,len,times,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[16][16];
pair<int,int>a[10];
string tot;
int vis[16][16];
queue<pair<pair<int,string>,deque<pair<int,int> > > >q;
bool ok(int x,int y,string z){
	if(x<0||x>=n||y<0||y>=m)return 0;
	if(vis[x][y]>50||c[x][y]=='#')return 0;
	if(z[x*m+y]=='0'+len)return 1;
	if(isdigit(z[x*m+y]))return 0;
	return 1;
}
deque<pair<int,int> >x;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j];
			tot+=c[i][j];
			if(isdigit(c[i][j]))
			{
				a[c[i][j]-'0']=make_pair(i,j);
				len=max(len,c[i][j]-'0');
			}
			if(c[i][j]=='1')
				vis[i][j]=1;
			if(c[i][j]=='@')
				a[0]=make_pair(i,j);
		}
	for(int i=1;i<=len;i++)
		x.push_back(a[i]);
	q.push(make_pair(make_pair(0,tot),x));
	while(!q.empty()){
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<q.front().first.second[i*m+j];
			cout<<endl;
		}
		cout<<endl;
		*/deque<pair<int,int> >xxx;
		xxx=q.front().second;
		if(xxx[0]==a[0])
		{
			cout<<q.front().first.first;
			return 0;
		}
		for(int i=0;i<4;i++)
		{
			if(ok(xxx[0].first+dx[i],xxx[0].second+dy[i],q.front().first.second))
			{
				string tot2=q.front().first.second;
				tot2[(xxx[0].first+dx[i])*m+xxx[0].second+dy[i]]='1';
				for(int j=0;j<xxx.size()-1;j++)
					tot2[xxx[j].first*m+xxx[j].second]=char(j+'2');
				tot2[xxx[xxx.size()-1].first*m+xxx[xxx.size()-1].second]='.';
				vis[(xxx[0].first+dx[i])][xxx[0].second+dy[i]]++;
				xxx.push_front(make_pair(xxx[0].first+dx[i],xxx[0].second+dy[i]));
				pair<int,int>tmp=xxx[xxx.size()-1];
				xxx.pop_back();
				q.push(make_pair(make_pair(q.front().first.first+1,tot2),xxx));
				xxx.pop_front();
				xxx.push_back(tmp);
			}
		}
		q.pop();
	}
	cout<<-1;
}