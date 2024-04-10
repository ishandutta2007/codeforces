#include<iostream>
#include<vector>
using namespace std;
#define R register int
inline long long Calc(vector<int>A,int x){
	long long res=0;
	for(auto T:A){
		int p=x-T;
		res+=p<0?-p:p;
		x+=2;
	}
	return res;
}
inline void Solve(){
	int n,x;
	cin>>n;
	vector<int>A,B;
	for(int i=0;i!=n;i++){
		cin>>x;
		if((x&1)==0){
			A.push_back(i);
		}else{
			B.push_back(i);
		}
	}
	if(A.size()+1<B.size()||A.size()>B.size()+1){
		cout<<-1<<endl;
		return;
	}
	if((n&1)==0){
		cout<<min(Calc(A,1),Calc(A,0));
	}else if(A.size()<B.size()){
		cout<<Calc(A,1);
	}else{
		cout<<Calc(A,0);
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}