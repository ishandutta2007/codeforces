#include<iostream>
using namespace std;
#define R register int
#define I inline
#define N 400001
int f[N],pos[N][2],a[N][2];
bool tag[N];
I int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
I void Merge(int x,int y){
	if(GetF(x)!=GetF(y)){
		f[f[x]]=y;
	}
}
I void Solve(){
	int n,ans=1;
	cin>>n;
	for(R i=1;i<=n;i++){
		f[i]=i;
		tag[i]=false;
	}
	for(R i=1;i<=n;i++){
		cin>>a[i][0];
		pos[a[i][0]][0]=i;
	}
	for(R i=1;i<=n;i++){
		cin>>a[i][1];
		pos[a[i][1]][1]=i;
	}
	for(R i=1;i<=n;i++){
		Merge(i,pos[a[i][0]][1]);
		Merge(i,pos[a[i][1]][0]);
	}
	for(R i=1;i<=n;i++){
		tag[GetF(i)]=true;
	}
	for(R i=1;i<=n;i++){
		if(tag[i]==true){
			ans<<=1;
			if(ans>1000000007){
				ans-=1000000007;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}