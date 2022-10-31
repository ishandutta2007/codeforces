#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
vector<int>A,B;
int main(){
	int n,l,m1,m2,ct=0,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d%d",&l,&m1);
		m2=m1;
		bool tag=false;
		for(R i=1;i!=l;i++){
			scanf("%d",&x);
			if(x>m1){
				tag=true;
			}else{
				m1=x;
			}
			if(x>m2){
				m2=x;
			}
		}
		if(tag==true){
			ct++;
		}else{
			A.push_back(m1);
			B.push_back(m2);
		}
	}
	x=n-ct;
	L ans=(L)ct*ct+((L)ct*x<<1);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(R i=0;i!=x;i++){
		ans+=lower_bound(A.begin(),A.end(),B[i])-A.begin();
	}
	printf("%lld",ans);
	return 0;
}