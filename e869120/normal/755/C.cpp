#include<iostream>
#include<queue>
using namespace std;
vector<int>x[100000];int n,a;bool used[100000];
int main(){
	cin>>n;for(int i=1;i<=n;i++){cin>>a;x[i].push_back(a);x[a].push_back(i);}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(used[i]==true)continue;
		queue<int>Q;cnt++;Q.push(i);used[i]=true;
		while(!Q.empty()){
			int a1=Q.front();Q.pop();
			for(int j=0;j<x[a1].size();j++){
				if(used[x[a1][j]]==false){
					Q.push(x[a1][j]);used[x[a1][j]]=true;
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}