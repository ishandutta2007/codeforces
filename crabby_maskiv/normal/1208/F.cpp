#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef pair<int,int> pii;
const int N=1<<21;
int a[N];
inline pii cmb(pii x,pii y){
	if(x.sc>=y.fr) return x;
	if(y.sc>=x.fr) return y;
	if(x.fr>=y.fr) return {x.fr,y.fr};
	else return {y.fr,x.fr};
}
pii f[N];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,k;
	cin>>n;
	for(i=0;i<N;i++) f[i]={0,0};
	for(i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=cmb(f[a[i]],{i,0});
	}
	for(j=1;j<N;j<<=1){
		for(i=0;i<N;i+=(j<<1))
			for(k=0;k<j;k++)
				f[i+k]=cmb(f[i+k],f[i+j+k]);
	}
	int answ=0;
	for(i=1;i<n-1;i++){
		int x=0,ans=0;
		for(j=20;j>=0;j--){
			if(a[i]>>j&1){
				ans|=(1<<j);
				continue;
			}
			x|=(1<<j);
			if(f[x].sc>i) ans|=(1<<j);
			else x^=(1<<j);
		}
		answ=max(answ,ans);
	}
	cout<<answ;
	return 0;
}