#include<iostream>
#include<vector>
using namespace std;
#define R register int
struct Edge{
	int Start,End;
};
inline Edge Pair(int x,int y){
	Edge res;
	res.Start=x;
	res.End=y;
	return res; 
}
int dis[2001];
int main(){
	int n,d;
	cin>>n;
	vector<int>A[2];
	cout<<"? 1"<<endl;
	for(int i=1;i<=n;i++){
		cin>>dis[i];
		A[dis[i]&1].push_back(i);
	}
	short t=A[0].size()<A[1].size()+1?0:1;
	vector<Edge>E;
	if(t==0){
		for(R i=2;i<=n;i++){
			if(dis[i]==1){
				E.push_back(Pair(1,i));
			}
		}
	}
	for(R i=2;i<=n;i++){
		if((dis[i]&1)==t){
			cout<<"? "<<i<<endl;
			for(R j=1;j<=n;j++){
				cin>>d;
				if(d==1){
					E.push_back(Pair(i,j));
				}
			}
		}
	}
	cout<<'!'<<endl;
	for(vector<Edge>::iterator T=E.begin();T!=E.end();T++){
		cout<<T->Start<<' '<<T->End<<endl;
	}
	return 0;
}