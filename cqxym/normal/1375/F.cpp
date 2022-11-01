#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
inline void Solve(L*A,int*D){
	L t=(A[D[2]]<<1)-A[D[1]]-A[D[0]];
	cout<<t<<endl;
	int x;
	cin>>x;
	x--;
	if(x==D[0]){
		cout<<A[D[2]]-A[D[1]]<<endl;
	}else if(x==D[1]){
		cout<<A[D[2]]-A[D[0]]<<endl;
	}else{
		A[D[2]]+=t;
		Solve(A,D);
	}
}
int main(){
	L a[3];
	int id[3]={0,1,2};
	cin>>a[0]>>a[1]>>a[2];
	sort(id,id+3,[&](int x,int y){return a[x]<a[y];});
	cout<<"First\n";
	Solve(a,id);
	return 0;
}