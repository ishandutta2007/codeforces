#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define R register int
set<int>S[200001];
int a[200000];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(int i=0;i!=n;i++){
		scanf("%d",a+i);
		S[a[i]].insert(i);
	}
	int mex,pos,pre=0;
	vector<int>A;
	while(true){
		mex=pos=0;
		while(S[mex].empty()==false){
			if(*S[mex].begin()>pos){
				pos=*S[mex].begin();
			}
			mex++;
		}
		if(mex==0){
			break;
		}
		A.push_back(mex);
		for(R i=pre;i<=pos;i++){
			S[a[i]].erase(S[a[i]].begin());
		}
		pre=pos+1;
	}
	for(R i=1;i<=n;i++){
		for(R j=0;j!=S[i].size();j++){
			A.push_back(0);
		}
		S[i].clear();
	}
	cout<<A.size()<<endl;
	for(int T:A){
		cout<<T<<' ';
	}
	cout<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}