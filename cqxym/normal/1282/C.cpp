#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
struct Test{
	int id;
	long long t;
	friend bool operator<(Test x,Test y){
		return x.t<y.t;
	}
}A[200001];
long long time[200001];
vector<int>D[2];
int n,T,a,b;
inline int Get(int s){
	Test Tem;
	Tem.t=s;
	int x=upper_bound(A+1,A+1+n,Tem)-A-1;
	/*int x=upper_bound(time+1,time+1+n,s)-time-1;*/
	long long u=time[x];
	if(u>s){
		return 0;
	}
	u=s-u;
	int la=upper_bound(D[0].begin(),D[0].end(),s)-D[0].begin();
	int lb=upper_bound(D[1].begin(),D[1].end(),s)-D[1].begin();
	la=D[0].size()-la;
	lb=D[1].size()-lb;
	//printf("X%d ",u);
	int ss=0;
	if(u/a>la){
		ss+=la;
		u-=la*a;
	}else{
		ss+=u/a;
		u%=a;
	}
	if(u/b>lb){
		ss+=lb;
	}else{
		ss+=u/b;
	}
	//printf("%d %d %d %d %d\n",x,s,la,lb,ss+x);
	return ss+x;
}
inline void Max(int &x,int y){
	x=x>y?x:y;
}
inline void Solve(){
	D[0].clear();
	D[1].clear(); 
	int x,y;
	scanf("%d%d%d%d",&n,&T,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i].id);
		D[A[i].id].push_back(i);
	}
	for(R i=1;i<=n;i++){
		scanf("%lld",&A[i].t);
	}
	int l=D[0].size();
	for(R i=0;i<l;i++){
		D[0][i]=A[D[0][i]].t;
	}
	l=D[1].size();
	for(R i=0;i<l;i++){
		D[1][i]=A[D[1][i]].t;
	}
	sort(D[1].begin(),D[1].end());
	sort(D[0].begin(),D[0].end());
	sort(A+1,A+n+1);
	int ans=0;
	for(R i=1;i<=n;i++){
		time[i]=time[i-1];
		if(A[i].id==0){
			time[i]+=a;
		}else{
			time[i]+=b;
		}
	}
	for(R i=1;i<=n;i++){
		x=Get(A[i].t);
		if(time[i]<=T){
			Max(x,Get(time[i]));
		}
		Max(x,Get(time[i]-1));
		if(A[i].t>0){
			Max(x,Get(A[i].t-1));
		}
		Max(ans,x); 
	}
	Max(ans,Get(T));
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
/*
1
3 5 1 3
0 0 1
2 1 4
*/