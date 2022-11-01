#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
int p[10],v[10000];
vector<int>P[10000];
inline void Solve(){
	int n,s=0,d;
	scanf("%d",&n);
	for(R i=0;i<1e4;i++){
		v[i]=0;
		P[i].clear();
	}
	for(R i=0;i<n;i++){
		scanf("%d",p+i);
		v[p[i]]++;
	}
	for(int i=0;i<1e4;i++){
		if(v[i]>1){
			s++;
			v[i]--;
			for(R j=0;j<10;j++){
				d=i-i%10+j;
				if(v[d]==0){
					v[d]=1;
					P[i].push_back(d);
					break;
				}
			}
			i--;
		}else if(v[i]!=0){
			P[i].push_back(i);
		}
	}
	printf("%d\n",s);
	for(R i=0;i<n;i++){
		d=P[p[i]].size();
		if(d!=0){
			d=P[p[i]][d-1];
			P[p[i]].pop_back();
			printf("%d%d%d%d\n",d/1000,d/100%10,d/10%10,d%10);
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}