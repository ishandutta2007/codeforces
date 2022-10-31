#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;
#define R register int
vector<int>A,B;
inline void Solve(){
	int n,t,m,s;
	scanf("%d",&n);
	t=sqrt(n);
	m=n;
	for(int i=2;i<=t&&m!=1;i++){
		if(m%i==0){
			A.push_back(i);
			s=0;
			do{
				m/=i;
				s++;
			}while(m%i==0);
			B.push_back(s);
		}
	}
	if(m!=1){
		A.push_back(m);
		B.push_back(1);
	}
	if(A.size()==1){
		if(B[0]>5){
			printf("YES\n%d %d %d\n",A[0],A[0]*A[0],n/A[0]/A[0]/A[0]);
		}else{
			puts("NO");
		}
	}else{
		t=A[0];
		m=A[1];
		s=n/t/m;
		if(t!=m&&t!=s&&m!=s&&s!=1){
			printf("YES\n%d %d %d\n",t,m,s);
		}else{
			puts("NO");
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		A.clear();
		B.clear();
		Solve();
	}
	return 0;
}