#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
const int maxm=2005;

int n,m;
long long p;
long long a[maxn],b[maxm];
long long l[maxn],r[maxn];

bool chk(long long q){
	for(int i=1;i<=n;i++){
		long long lf;
		if(a[i]>=p){
			lf=q-(a[i]-p);
			l[i]=p-(lf>>1);
			r[i]=a[i]+(lf>>1);
		}else{
			lf=q-(p-a[i]);
			l[i]=a[i]-(lf>>1);
			r[i]=p+(lf>>1);
		}
		if(lf<0) return 0;
	}
	int cp=1;
	for(int i=1;i<=n;i++){
		while(b[cp]<l[i]&&cp<=m)cp++;
		if(cp>m)return 0;
		if(b[cp]>r[i])return 0;
		cp++;
	}
	return 1;
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	long long l=0,r=1e10;
	while(r-l>3){
		long long m=(l+r)>>1;
		if(chk(m))r=m;
		else l=m;	
	}
	for(long long i=l;i<=r;i++){
		if(chk(i)){
			cout<<i;
			return 0;
		}
	}
    return 0;
}