#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
#define R register int
inline int Query(int a,int b,int c){
	cout<<"? "<<a<<' '<<b<<' '<<c<<endl;
	cin>>a;
	return a;
}
int p[100001];
vector<int>A[100001];
inline void Solve(){
	int n,x,a,b,c,pos1,pos2,maxV;
	cin>>n;
	maxV=n;
	for(R i=0;i<=n;i++){
		A[i].clear();
	}
	do{
		a=rand()%n+1;
		do{
			b=rand()%n+1;
		}while(a==b);
		do{
			c=rand()%n+1;
		}while(a==c||b==c);
		x=Query(a,b,c);
	}while(x>(n-4)/6);
	for(int i=1;i<=n;i++){
		if(i!=a&&i!=b){
			A[Query(a,b,i)].push_back(i);
		}
	}
	while(A[maxV].empty()==true){
		maxV--;
	}
	pos1=A[maxV][0];
	p[pos1]=1;
	maxV--;
	if(A[maxV].size()==2&&Query(pos1,A[maxV][0],a)>Query(pos1,A[maxV][1],a)){
		pos2=A[maxV][1];
	}else{
		pos2=A[maxV][0];
	}
	p[pos2]=2;
	for(R i=1;i<=n;i++){
		if(i!=pos1&&i!=pos2){
			p[i]=Query(pos1,pos2,i)+2;
		}
	}
	if(p[1]>p[2]){
		for(R i=1;i<=n;i++){
			p[i]=n-p[i]+1;
		}
	}
	cout<<'!';
	for(R i=1;i<=n;i++){
		cout<<' '<<p[i];
	}
	cout<<endl;
	cin>>n;
}
int main(){
	srand(time(0));
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}