#include <iostream>
#include <vector>
using namespace std;

int k,n,m;
vector <int> aa[1000010];
bool f[1000010];

int dfs(int v){
	f[v]=true;
	int res=1;
	for(int i=0;i<int(aa[v].size());i++){
		int a=aa[v][i];
		if(!f[a])res+=dfs(a);
	}
	return res;
}

int main(){
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		aa[x].push_back(y);
		aa[y].push_back(x);
	}
	int s=2;
	int q=0;
	for(int i=1;i<=n;i++)if(!f[i]){
		s+=min(dfs(i),k)-2;
		q++;
	}
	if(k==1)cout << max(q-2,0);
	else if(s>=0)cout <<  0;
	else cout <<  (-s+1)/2;
}