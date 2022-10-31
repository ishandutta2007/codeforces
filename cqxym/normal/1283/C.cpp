#include<stdio.h>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define R register int
vector<int>A,B;
bool t[200001];
int ans[200001],l;
inline bool Check(){
	for(R i=0;i!=l;i++){
		if(A[i]==B[i]){
			return false;
		}
	}
	return true;
}
int main(){
	srand((int)time(0));
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",ans+i);
		if(ans[i]==0){
			A.push_back(i);
		}else{
			t[ans[i]]=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==false){
			B.push_back(i);
		}
	}
	l=A.size();
	while(Check()==false){
		random_shuffle(A.begin(),A.end());
	}
	for(R i=0;i!=l;i++){
		ans[A[i]]=B[i];
	}
	for(R i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}