#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define pb push_back
#define mp make_pair
using namespace std;

int n,m,p,q;
char c[250][250];
int noise[250][250];
int use[250][250];
int d1[4]={0,0,1,-1},d2[4]={1,-1,0,0}; 
vector<pair<int,int> > vvis;
int dist[255][255];
void bfs(int a,int b,int energy){
	vvis.clear();
	queue<pair<int,int> > Q;
	Q.push(mp(a,b));
	dist[a][b]=energy;
	while (!Q.empty()){
		pair<int,int> x=Q.front();
		Q.pop();
		if (dist[x.first][x.second]<=1) continue;
		for (int i=0;i<4;i++){
			int X=x.first+d1[i],Y=x.second+d2[i];
			if (X>=0 && Y>=0 && X<n && Y<m && dist[X][Y]==0 && c[X][Y]!='*'){
				dist[X][Y]=dist[x.first][x.second]/2;
				Q.push(mp(X,Y));
				vvis.pb(mp(X,Y));
			}
		}
	}
	vvis.pb(mp(a,b));
	for (int i=0;i<vvis.size();i++){
		noise[vvis[i].first][vvis[i].second]+=dist[vvis[i].first][vvis[i].second];
		dist[vvis[i].first][vvis[i].second]=0;
	}
}

int main()
{
	cin>>n>>m>>p>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
			
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i][j]<='Z'&&c[i][j]>='A')
			{
				bfs(i,j,(c[i][j]-'A'+1)*p);	
			}
		
	int ans=0;	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{
			if(noise[i][j]>q)
				ans++;
		//	cout<<noise[i][j]<<" "; 
		}
	//	cout<<endl; 
	}
		
	cout<<ans<<endl;
	return 0;
}