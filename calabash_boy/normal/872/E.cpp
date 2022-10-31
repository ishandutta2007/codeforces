#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const int MOD = 1e9+7;
long long ans =1;
int fa[maxn*2];
int pcnt[maxn*2],ecnt[maxn*2];
int xx[maxn],yy[maxn]; 
int n,cnt;
map<int,int> hsx,hsy;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long power(long long x,long long y){
	if(!y)return 1; 
	if (y&1){
		return x*power(x*x%MOD,y/2)%MOD;
	}else{
		return power(x*x%MOD,y/2)%MOD;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",xx+i,yy+i);
		if (!hsx.count(xx[i]))hsx.insert(make_pair(xx[i],cnt++));
		if (!hsy.count(yy[i]))hsy.insert(make_pair(yy[i],cnt++));
	}
	for (int i=0;i<cnt;i++){
		fa[i]=i;
	}
	for (int i=0;i<n;i++){
		fa[find(hsx[xx[i]])]=find(hsy[yy[i]]);
	}
	for (int i=0;i<n;i++){
		pcnt[find(hsx[xx[i]])]++;
	}
	for (int i=0;i<cnt;i++){
		ecnt[find(i)]++;
	}
	for (int i=0;i<cnt;i++){
		if (i==find(i)){
//			cout<<pcnt[i]<<" "<<ecnt[i]<<endl;
			if (pcnt[i]==ecnt[i]-1){
				ans=ans*(power(2,ecnt[i])-1)%MOD;
			}else{
				ans = ans*power(2,ecnt[i])%MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}