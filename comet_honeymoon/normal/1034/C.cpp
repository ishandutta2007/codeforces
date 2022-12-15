#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll s[1000005];int fa[1000005];
ll S;
ll f[1000005],ans;
const int p=1000000007;

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&s[i]);
	for(int i=2;i<=N;i++) scanf("%d",&fa[i]);
	for(int i=N;i;i--) s[fa[i]]+=s[i];
	S=s[1];
	for(int i=1;i<=N;i++) if(S/gcd(s[i],S)<=N) f[S/gcd(s[i],S)]++;
	for(int i=N;i;i--)
	for(int j=i+i;j<=N;j+=i)
		f[j]+=f[i];
	for(int i=1;i<=N;i++) f[i]=(f[i]==i);
	for(int i=N;i>1;i--)if(f[i]){
		for(int j=i+i;j<=N;j+=i) f[i]=(f[i]+f[j])%p;
		ans=(ans+f[i])%p;
	}
	printf("%d\n",ans+1);
}