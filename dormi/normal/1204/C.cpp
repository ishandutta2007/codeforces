#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
bool matrix[101][101];
int shortest[101][101];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string a;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=1;j<=n;j++){
			matrix[i][j]=(a[j-1]=='1');
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			queue<int> q;
			q.push(i);
			int dist[n+1];
			for(int k=1;k<=n;k++)dist[k]=INT_MAX;
			dist[i]=0;
			while(!q.empty()){
				int cur=q.front();
				q.pop();
				for(int k=1;k<=n;k++){
					if(matrix[cur][k]&&dist[k]>dist[cur]+1){
						dist[k]=dist[cur]+1;
						q.push(k);
					}
				}
			}
			shortest[i][j]=dist[j];
		}
	}
	int m;
	cin>>m;
	int last;
	cin>>last;
	int in;
	vector<int> ans;
	ans.push_back(last);
	int lastloc=0;
	int prev=last;
	for(int i=1;i<m;i++){
		cin>>in;
		if(shortest[last][in]!=i-lastloc){
			ans.push_back(prev);
			last=prev;
			lastloc=i-1;
		}
		prev=in;
	}
	ans.push_back(prev);
	printf("%d\n",ans.size());
	for(int i:ans)printf("%d ",i);
	return 0;
}