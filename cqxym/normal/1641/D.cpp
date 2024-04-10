#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<memory>
using namespace std;
#define R register int
#define I inline
#define N 100001
#define INF 2000000009
struct Array{
	vector<int>Num;
	int Val;
	I void Read(const int m){
		Num.resize(m);
		for(R i=0;i!=m;i++){
			scanf("%d",&Num[i]);
		}
		scanf("%d",&Val);
	}
	I friend bool operator<(Array A,Array B){
		return A.Val<B.Val;
	}
}a[N];
unique_ptr<bitset<N>>F[500000];
vector<int>Id[500000];
int main(){
	int n,m,tot,l,ans=INF;
	scanf("%d%d",&n,&m);
	vector<int>B;
	for(R i=0;i!=n;i++){
		a[i].Read(m);
		for(int T:a[i].Num){
			B.push_back(T);
		}
	}
	sort(B.begin(),B.end());
	tot=unique(B.begin(),B.end())-B.begin();
	while(B.size()>tot){
		B.pop_back();
	}
	for(R i=0;i!=n;i++){
		for(int&T:a[i].Num){
			T=lower_bound(B.begin(),B.end(),T)-B.begin();
		}
	}
	sort(a,a+n);
	for(int i=0;i!=n;i++){
		for(int T:a[i].Num){
			Id[T].push_back(i);
		}
	}
	for(R i=0;i!=tot;i++){
		if(Id[i].size()>999){
			F[i]=make_unique<bitset<N>>();
			for(int T:Id[i]){
				F[i]->set(T);
			}
		}
	}
	for(R i=0;i!=n;i++){
		bitset<N>S;
		S[i]=1;
		for(R j=0;j!=m;j++){
			l=a[i].Num[j];
			if(Id[l].size()>999){
				S|=*F[a[i].Num[j]];
			}else{
				for(int T:Id[l]){
					S[T]=1;
				}
			}
		}
		S.flip();
		l=S._Find_first();
		if(l<n&&a[i].Val+a[l].Val<ans){
			ans=a[i].Val+a[l].Val;
		}
	}
	if(ans==INF){
		printf("-1");
	}else{
		printf("%d",ans);
	}
	return 0;
}