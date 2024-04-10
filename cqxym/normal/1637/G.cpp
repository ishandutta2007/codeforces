#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline void
I Erase(vector<int>&A,int x){
	A[x]=A.back();
	A.pop_back();
}
I Construct(int n,int b,vector<pair<int,int>>&A,vector<int>&B){
	if(n>2){
		int m=2;
		while(m<<1<=n){
			m<<=1;
		}
		B.push_back(m<<b);
		if(m==n){
			Construct(n-1,b,A,B);
		}else{
			Construct((m<<1)-n-1,b,A,B);
			for(R i=n;i!=m;i--){
				int x=(m<<1)-i;
				A.push_back(make_pair(x<<b,i<<b));
				B.push_back(m<<1<<b);
			}
			Construct(n-m,b+1,A,B);
		}
	}else{
		for(R i=1;i<=n;i++){
			B.push_back(i<<b);
		}
	}
}
I Solve(){
	int n;
	scanf("%d",&n);
	if(n==2){
		puts("-1");
	}else{
		vector<pair<int,int>>A;
		vector<int>B;
		Construct(n,0,A,B);
		int s=B.size(),m=4;
		while(m<n){
			m<<=1;
		}
		for(int i=1;i!=m;i<<=1){
			int x=-1,y=-1;
			for(R j=0;j!=s;j++){
				if(B[j]==i){
					if(x==-1){
						x=j;
					}else{
						y=j;
						break;
					}
				}
			}
			if(y!=-1){
				Erase(B,y);
				Erase(B,x);
				A.push_back(make_pair(i,i));
				B.push_back(i<<1);
				break;
			}
		}
		for(int T:B){
			while(T<n){
				A.push_back(make_pair(0,T));
				A.push_back(make_pair(T,T));
				T<<=1;
			}
		}
		A.push_back(make_pair(m,0));
		printf("%d\n",A.size());
		for(auto T:A){
			printf("%d %d\n",T.first,T.second);
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}