#include<bits/stdc++.h>
#define ll long long
#define N 200002
#define pb push_back 
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char a[N];
vector<int>b[N*2];
int id(int k,int r){
	return (1<<k)+r;
}
int main(){
	int n,i,j,k,q,l,r,m,ans;
	scanf("%d",&n);scanf("%s",a);
	for(i=0;i<n;++i)a[i]-=48;
	for(i=n-1;i>=1;--i)a[i]^=a[i-1];
	for(i=0;(1<<i)<n;++i){
		for(j=0;j<(1<<i);++j){
			b[id(i,j)].pb(0);
			l=0;
			for(k=j;k<n;k+=(1<<i)){
				l+=a[k];
				b[id(i,j)].pb(l);
			}
		}
	}
	read(q);
	while(q--){
		scanf("%d%d",&l,&r);
		ans=0;
		if(l>r)swap(l,r);
		m=r-l+1;
		for(i=1;(1<<i)<n;++i){
			int t=(l+(1<<(i-1)))&((1<<i)-1);
			//printf("<%d %d>:",1<<i,t);
			int p=m>>i;
			int a1=((l+(1<<(i-1))-t)>>i),a2=a1+p,a3=b[id(i,t)][a2]-b[id(i,t)][a1];
			//printf("%d %d %d %d\n",a1,a2,a3,p);
			ans=ans+min(a3,p-a3);
		}
		printf("%d\n",(ans+1)>>1);
	}
	return 0;
}