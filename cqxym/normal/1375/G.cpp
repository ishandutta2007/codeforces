#include<iostream>
#include<vector>
using namespace std;
vector<int>G[200001];
inline void DFS(int x,int F,int d,int*C){
	C[d]++;
	for(int T:G[x]){
		if(T!=F){
			DFS(T,x,d^1,C);
		}
	}
}
int main(){
	int n,x,y,ct[2]={0,0};
	cin>>n;
	for(register int i=1;i!=n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1,0,0,ct);
	cout<<(ct[0]<ct[1]?ct[0]:ct[1])-1;
	return 0;
}