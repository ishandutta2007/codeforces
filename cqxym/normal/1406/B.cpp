#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
#define I inline
int v[100001];
I L Get1(int k,vector<int>&A){
	L res=1;
	int ct=0;
	for(vector<int>::iterator T=A.begin();ct!=k;ct++){
		res*=*T;
		T++;
	}
	return res;
}
I L Get2(int k,vector<int>&A){
	L res=1;
	int ct=0;
	for(vector<int>::iterator T=A.end()-1;ct!=k;ct++){
		res*=*T;
		T--;
	}
	return res;
}
I void Solve(){
	int n,x;
	scanf("%d",&n);
	vector<int>A,B;
	for(R i=1;i<=n;i++){
		scanf("%d",v+i);
		if(v[i]<0){
			A.push_back(v[i]); 
		}else{
			B.push_back(v[i]);
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	L ans=-1e18;
	for(R i=0;i!=6;i++){
		if(i<=A.size()&&5-i<=B.size()){
			L tem;
			if((i&1)==0){
				tem=Get1(i,A)*Get2(5-i,B);
			}else{
				tem=Get2(i,A)*Get1(5-i,B);
			}
			if(tem>ans){
				ans=tem;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}