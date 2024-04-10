#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool mp[MAX][MAX];
int n,k;
int ans;
vector<int> inMass;
int d[MAX]; 
int ac;
#define random(a,b) (a+rand()%((b)-(a)+1))
void dfs(int node){
//	cout<<"dfs("<<node<<")="<<inMass.size();
	ans = max(ans,(int)inMass.size());
	if (ans>=inMass.size()+n-node-1){
		return;
	}
	for (int i=node+1;i<n;i++){
		bool flag = true;
		if (d[i]<=ans){
			continue;
		}
		for (int temp:inMass){
			if (!mp[temp][i]){
				flag = false;
				break;
			}
		}
		if (flag){
			inMass.push_back(i);
			dfs(i);
			inMass.pop_back();
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			mp[i][j] = temp;
			d[i]++;
		}
	}
	dfs(-1);	
	double res = 1.0*(ans-1)/2.0/ans*k*k;
	printf("%.9f",res);
	return 0;
}