#include<bits/stdc++.h>
using namespace std;
const int maxn=21;
int n,k;
long double p[maxn],f[1<<maxn];
long double ans[maxn];
/*
f[x] S
x=2^Si  
aS
f[x|(2^a)]= f[x]*(Pa/Pa)
*/
//#define debug 1
void dp(int x){
	//x
	int cnt=0;
	long double tot=0;
	for(int i=1;i<=n;i++){
#ifdef debug
		cout<<i<<" "<<(x&(1<<(i-1)))<<endl;
#endif
		if((x&(1<<(i-1)))==0)
			tot+=p[i];
		else
			cnt++;
	}
#ifdef debug
	cout<<x<<" "<<tot<<" "<<cnt<<endl;
#endif
	if(cnt>k)
		return;
	else if(cnt==k)
		for(int i=1;i<=n;i++){
			if(x&(1<<(i-1)))
				ans[i]+=f[x];
		}
	else
		for(int i=1;i<=n;i++)
			if((x&(1<<(i-1)))==0)
				f[x|(1<<(i-1))]+=f[x]*(p[i]/tot);
}
signed main(){
	f[0]=1;int __tmp__=0;
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]>1e-8)__tmp__++;
		//cout<<p[i]<<endl;
	} 
	if(__tmp__<=k){// 
		//printf ("No way to fill\n");
		for(int i=1;i<=n;i++){
			if(p[i]>1e-8)
				printf("1 ");
			else
				printf("0 ");
		}
		return 0;
	}
	//
	for(int i=0;i<(1<<n);i++)
	 	dp(i);//i
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" "; 
}