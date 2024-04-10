#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
char a[100001],b[100001];
vector<int>A,B;
inline void Deal(char*s,int&n,vector<int>&T){
	getchar();
	for(R i=0;i!=n;i++){
		s[i]=getchar();
	}
	int lt=1;
	char tem=s[0];
	while(lt!=n){
		while(lt!=n&&s[lt]==tem){
			lt++;
		}
		if(lt!=n||s[n-1]=='1'){
			T.push_back(lt);
		}
		tem=s[lt];
	}
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	A.clear();
	B.clear();
	Deal(a,n,A);
	Deal(b,n,B);
	if(n==1){
		if(a[0]==b[0]){
			puts("0");
		}else{
			puts("1 1");
		}
		return;
	}
	printf("%d",A.size()+B.size());
	for(vector<int>::iterator T=A.begin();T!=A.end();T++){
		printf(" %d",*T);
	}
	for(vector<int>::iterator T=B.end();T!=B.begin();T--){
		printf(" %d",*(T-1));
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}