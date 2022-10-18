#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

const int maxn=10005;
const int mdn=1019260817; 
struct node{
	int i,n,x;
};

int l[maxn],r[maxn],x[maxn];
node cg[maxn<<1];
int n,q;
bool tok[maxn];
int ok[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i]>>x[i];
		cg[i<<1].i=l[i];cg[i<<1].n=1;cg[i<<1].x=x[i];
		cg[(i<<1)-1].i=r[i]+1;cg[(i<<1)-1].n=-1;cg[(i<<1)-1].x=x[i];
	}
	sort(cg+1,cg+1+q+q,[](node a,node b){
		if(a.i==b.i)return a.n<b.n;
		return a.i<b.i;
	});
	ok[0]=1;
	int cp=0;
	for(int i=1;i<=n;i++){
		while(cp!=(q<<1)&&cg[cp+1].i<=i){
			cp++;
			if(cg[cp].n==1){
				for(int j=n;j>=cg[cp].x;j--){
					ok[j]+=ok[j-cg[cp].x];
					ok[j]%=mdn; 
				} 
			}else{
				for(int j=cg[cp].x;j<=n;j++){
					ok[j]-=ok[j-cg[cp].x];
					ok[j]%=mdn;
				}
			} 	
		}
		for(int j=1;j<=n;j++){
			if(ok[j]!=0)tok[j]|=1;
		} 	
	} 
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(tok[i])cnt++; 
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++){
		if(tok[i])cout<<i<<' ';
	}
	return 0;
}