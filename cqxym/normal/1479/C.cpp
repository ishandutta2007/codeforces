#include<iostream>
#include<vector>
using namespace std;
#define R register int
#define I inline
struct Edge{
	int Start,End,Len;
};
I Edge Pair(int x,int y,int z){
	Edge Tem;
	Tem.Start=x;
	Tem.End=y;
	Tem.Len=z;
	return Tem;
}
vector<Edge>E;
I void AddEdge(int x,int y,int z){
	E.push_back(Pair(x,y,z));
}
I int Solve(int r,const bool type){
	int k=0;
	while(2<<k<=r){
		k++;
	}
	for(R i=1;i!=k+2;i++){
		for(R j=i+1;j!=k+3;j++){
			AddEdge(i+type,j+type,i==1?1:1<<i-2);
		}
	}
	if(1<<k!=r){
		int t=k+3+type,s;
		AddEdge(1+type,t,1);
		if((r&1)==1){
			r^=1;
			s=1;
		}else{
			AddEdge(2+type,t,1);
			r-=2;
			s=2;
		}
		for(R i=k;i!=0;i--){
			if((r>>i&1)==1){
				r^=1<<i;
				AddEdge(i+2+type,t,r+s);
			}
		}
		return k+3+type;
	}else{
		return k+2+type;
	}
}
int main(){
	cout<<"YES"<<endl;
	int l,r,n,m;
	cin>>l>>r;
	if(r==1){
		cout<<"2 1"<<endl<<"1 2 1";
		return 0;
	}
	if(l!=1){
		AddEdge(1,2,l-1);
		n=Solve(r-l+1,true);
	}else{
		n=Solve(r,false);
	}
	m=E.size();
	printf("%d %d",n,m);
	for(vector<Edge>::iterator T=E.begin();T!=E.end();T++){
		printf("\n%d %d %d",T->Start,T->End,T->Len);
	}
	return 0;
}