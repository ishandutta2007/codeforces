#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int G[maxn][maxn];
bool cmp(int i,int j)
{
	return G[i][j];
}
inline bool ask(int i,int j)
{
	if(G[i][j]||G[j][i]) return G[i][j];
	cout<<"? "<<i<<" "<<j<<endl;
	string ret;
	cin>>ret;
	if(ret==">") return 1;
	return 0;
}
typedef vector<int> vi;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=2*n;i++)
			for(int j=0;j<=2*n;j++)
				G[i][j]=0;
		vector<int> line;
		for(int i=1;i<=n;i++)
		{
			if(ask(i,i+n))
			{
				G[i][i+n]=1;
				line.push_back(i+n);
			}
			else{
				G[i+n][i]=1;
				line.push_back(i);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int u=line[i],v=line[j];
				if(ask(u,v))
					G[u][v]=1;
				else G[v][u]=1;
			}
		}
		sort(line.begin(),line.end(),cmp);
		vector<int> res;
		for(int i=1;i<n;i++){
			int u=line[i],v;
			res.push_back(u);
			if(u>n) v=u-n;
			else v=u+n;
			res.push_back(v);
			for(int j=i+1;j<n;j++){
				int uu=line[j],vv;
				if(uu>n) vv=uu-n;
				else vv=uu+n;
				if(ask(v,uu)) G[v][uu]=1;
				else G[uu][v]=1;
				if(ask(v,vv)) G[v][vv]=1;
				else G[vv][v]=1;
				if(ask(vv,u)) G[vv][u]=1;
				else G[u][vv]=1;
			}
		}
		sort(res.begin(),res.end(),cmp);
		if(res[n-1]==line[1]){
			ask(res[n-2],line[0]);
		}
		cout<<"!"<<endl;
	}
}
// 1 5 3 4 2 6