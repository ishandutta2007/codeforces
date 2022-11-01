#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define R register int
vector<int>G[1001];
int f[1001];
inline void DFS(int x,int F,vector<int>&E){
	f[x]=F;
	for(auto T:G[x]){
		if(T!=F){
			E.push_back(T);
			DFS(T,x,E);
			E.push_back(T);
		}
	}
}
inline int Ask(vector<int>&A){
	cout<<"? "<<A.size();
	for(auto T:A){
		cout<<' '<<T; 
	}
	cout<<endl;
	int x;
	cin>>x;
	return x;
}
int main(){
	int n,x,y,l=0,r,mid;
	cin>>n;
	for(R i=1;i!=n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<int>E,A;
	DFS(1,0,E);
	for(int i=1;i<=n;i++){
		A.push_back(i);
	}
	x=Ask(A);
	r=E.size()-1;
	/*cout<<"E"<<endl;
	for(auto T:E){
		cout<<T<<' ';
	}*/
	cout<<endl;
	while(l<r){
		mid=l+r>>1;
		set<int>S;
		for(R i=l;i<=mid;i++){
			S.insert(f[E[i]]);
			S.insert(E[i]);
		}
		A.clear();
		for(auto T:S){
			A.push_back(T);
		}
		//printf("R%d %d\n",l,r);
		if(Ask(A)==x){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<"! "<<f[E[l]]<<' '<<E[r]<<endl;
	return 0;
}
/*
7
1 2
1 3
2 4
2 5
3 6
3 7

7
1 2 1
1 3 3
2 4 5
2 5 2
3 6 7
3 7 6
*/