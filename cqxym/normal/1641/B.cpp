#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define R register int
inline void Solve(int base,vector<int>&A,vector<pair<int,int>>&Add,vector<int>&Seg){
	int n=A.size(),pos;
	if(n!=0){
		for(R i=1;i!=n;i++){
			if(A[i]==A[0]){
				pos=i;
				break;
			}
		}
		Seg.push_back(pos<<1);
		vector<int>B;
		for(R i=pos-1;i!=0;i--){
			B.push_back(A[i]);
		}
		for(R i=pos+1;i!=n;i++){
			B.push_back(A[i]);
		}
		int cur=base+pos;
		for(R i=1;i!=pos;i++){
			cur++;
			Add.push_back(make_pair(cur,A[i])); 
		}
		Solve(base+(pos<<1),B,Add,Seg);
	}
}
int main(){
	int t,n,x;
	cin>>t;
	for(R i=0;i!=t;i++){
		cin>>n;
		vector<int>A,Seg;
		map<int,int>Q;
		for(R j=0;j!=n;j++){
			cin>>x;
			A.push_back(x);
			Q[x]++;
		}
		vector<pair<int,int>>Add;
		for(auto T:Q){
			if((T.second&1)==1){
				cout<<"-1\n";
				goto Fail;
			}
		}
		Solve(0,A,Add,Seg);
		cout<<Add.size()<<endl;
		for(auto T:Add){
			cout<<T.first<<" "<<T.second<<endl;
		}
		cout<<Seg.size()<<endl;
		for(int T:Seg){
			cout<<T<<" ";
		}
		cout<<endl;
		Fail:;
	}
	return 0;
}