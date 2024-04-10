#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=21000010;
int i,j,k,n,m,T,x,prime[maxn],is_prime[maxn],num[maxn],cnt;
void init(){
	for(int i=2;i<maxn;i++)is_prime[i]=1;
	for(int i=2;i<maxn;i++){
		if(is_prime[i])prime[++cnt]=i,num[i]=1;
		for(int j=1;j<=cnt && prime[j]*i<maxn;j++){
			is_prime[i*prime[j]]=0;
			num[i*prime[j]]=num[i];
			if(i%prime[j]==0)break;
			num[i*prime[j]]=num[i]+1;
		}
	}
}
ll check(int a,int b){
	int B=a;
	int A=(b+m);
	if(A%n!=0)return 0;
	A/=n;
	ll ans=1;
	return ans<<num[A];
	/*
	for(int i=1;prime[i]<=A;i++){
		int S1=0,S2=0;
		if(A%prime[i]==0)S2++,A/=prime[i];
		if(S2)ans<<=1;
	}return ans;
	*/
}
int main(){;
	cin>>T;
	init();
	while(T--){
		ll ans=0;
		n=read();m=read();x=read();
		for(int i=1;i<=sqrt(x);i++){
			if(x%i==0){
				int a=x/i,b=i;
				ans+=check(a,b);
				if(a!=b)ans+=check(b,a);
			}
		}
		cout<<ans<<endl;
	}
}