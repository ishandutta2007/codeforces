#include<iostream>
#include<vector>
using namespace std;
#define R register int
int a[1000];
bool tag[1001];
inline int GetMex(const int n){
	for(R i=0;i!=n;i++){
		tag[a[i]]=true;
	}
	int res=n;
	for(R i=0;i!=n;i++){
		if(tag[i]==false){
			res=i;
			break;
		}
	}
	for(R i=0;i!=n;i++){
		tag[a[i]]=false;
	}
	return res;
}
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	vector<int>A;
	while(true){
		int pos=-1;
		for(R i=0;i!=n;i++){
			if(a[i]!=i){
				pos=i;
				break;
			}
		}
		if(pos==-1){
			break;
		}
		int t=GetMex(n);
		if(t==n){
			A.push_back(pos);
			a[pos]=n;
		}else{
			A.push_back(t);
			a[t]=t;
		}
	}
	cout<<A.size()<<endl;
	for(int T:A){
		cout<<T+1<<" ";
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
/*
1
10
8 9 10 0 0 0 0 0 0 0
*/