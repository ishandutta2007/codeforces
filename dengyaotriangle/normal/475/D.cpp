#include <bits/stdc++.h>
using namespace std;

const int maxn=100006;
const int maxt=20;

int n,q;
long long a[maxn];
long long st[maxn][maxt];
long long pwr2[maxt];
map<long long,long long> m; 

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

long long gm(int l,int r) {
	if(r>n) return 0;
	int lg=log2(r-l+1);
	return gcd(st[l][lg],st[r-pwr2[lg]+1][lg]);
}
 
int main(){
	cin>>n;
	pwr2[0]=1;
	for(int i=1;i<maxt;i++)pwr2[i]=pwr2[i-1]*2;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int i=1;i<maxt;i++){
		for(int j=1;j<=n;j++){
			if(j+pwr2[i]-1>n) break;
			st[j][i]=gcd(st[j][i-1],st[j+pwr2[i-1]][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		int master_l=i;
		while(1){
			int l=master_l,r=n+1;
			long long targ=gm(i,master_l);
			while(r-l>3){
				int m=(l+r)/2;
				if(gm(i,m)<targ) r=m;
				else l=m;
			}
			for(int j=l;j<=r;j++){
				if(gm(i,j)<targ){
					m[targ]=m[targ]+j-master_l;
					master_l=j;
					break;
				}
			}
			if(master_l>n) break;
		}
	}
	cin>>q;
	while(q--){
		long long x;
		cin>>x;
		cout<<m[x]<<endl; 
	} 
	return 0;
}