#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define P 998244353
inline int Add(int x,int y){
	x+=y;
	return x<P?x:x-P;
}
int a[100001];
struct DP{
	int Lval,DpF,DpG;
};
inline DP Pair(int l,int f,int g){
	DP res;
	res.Lval=l;
	res.DpF=f;
	res.DpG=g;
	return res;
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	vector<DP>A;
	A.push_back(Pair(a[n],1,0));
	int ans=0;
	for(R i=n-1;i!=0;i--){
		vector<pair<int,int>>C;
		int t,r;
		for(int j=1;j<a[i];j=r+1){
			t=(a[i]+j-1)/j;
			r=(a[i]-1)/(t-1);
			C.push_back(make_pair(t,j));
		}
		C.push_back(make_pair(1,a[i]));
		auto T2=A.begin();
		int pref=0,preg=0,sumf=0,sumg=0;
		vector<DP>B;
		for(auto T1:C){
			while(T2!=A.end()&&T2->Lval>=T1.first){
				sumf=Add(sumf,T2->DpF);
				sumg=Add(sumg,T2->DpG);
				T2++;
			}
			int lf=a[i]/T1.second;
			B.push_back(Pair(lf,Add(sumf,P-pref),((T1.second-1ll)*(sumf+P-pref)+sumg+P-preg)%P));
			pref=sumf;
			preg=sumg;
		}
		B[0].DpF=Add(B[0].DpF,1);
		A.swap(B);
		for(DP T:A){
			ans=Add(ans,T.DpG);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}