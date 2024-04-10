#include<stdio.h>
#include<queue>
#include<algorithm>
#define R register int
#define L long long
using namespace std;
const int N=200002;
struct Seg{
	int l,r,id;
}f[N];
struct Cho{
	int r,id;
	friend bool operator<(Cho x,Cho y){
		return x.r<y.r;
	}
}; 
priority_queue<Cho>Q;
bool Com(Seg x,Seg y){
	return x.l<y.l;
}
int ans[N],del[N];
int main(){
	int n,m=0,k;
	scanf("%d%d",&n,&k);
	for(R i=0;i<n;i++){
		scanf("%d%d",&f[i].l,&f[i].r);
		f[i].id=i+1;
		del[f[i].r+1]++;
	}
	sort(f,f+n,Com);
	R j=0;
	for(R i=1;i<N;i++){
		del[i]+=del[i-1];
		while(j<n&&f[j].l==i){
			Cho E;
			E.id=f[j].id;
			E.r=f[j].r;
			Q.push(E);
			j++;
		}
		while(Q.size()>k+del[i]){
			ans[m]=Q.top().id;
			del[Q.top().r+1]--;
			m++;
			Q.pop();
		}
	}
	printf("%d\n",m);
	for(R i=0;i<m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}