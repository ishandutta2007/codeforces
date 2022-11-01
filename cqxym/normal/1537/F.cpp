#include<iostream>
using namespace std;
#define R register int
int f[200001],a[200001];
bool v[200001];
inline int GetF(int x){
	if(f[x]==x){
		return x;
	}
	int d=GetF(f[x]);
	v[x]^=v[f[x]];
	f[x]=d;
	return d;
}
inline void Solve(){
	int n,m,x,y;
	cin>>n>>m;
	for(R i=1;i<=n;i++){
		f[i]=i;
		v[i]=false;
		cin>>a[i];
	}
	for(R i=1;i<=n;i++){
		cin>>x;
		a[i]-=x;
	}
	bool tag=false;
	for(R i=0;i!=m;i++){
		cin>>x>>y;
		if(GetF(x)!=GetF(y)){
			v[f[x]]=v[x]^true;
			f[f[x]]=y;
		}else if(v[x]==v[y]){
			tag=true;
		}
	}
	if(tag==true){
		int sum=0;
		for(R i=1;i<=n;i++){
			sum^=a[i];
		}
		if((sum&1)==1){
			puts("NO");
		}else{
			puts("YES");
		}
	}else{
		long long sum1=0,sum2=0;
		for(R i=1;i<=n;i++){
			GetF(i);
			if(v[i]==true){
				sum1+=a[i]; 
			}else{
				sum2+=a[i];
			}
		}
		if(sum1==sum2){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}