#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,N;
ll a[1000005],A;
void sol(ll i){
	ll t=i*i+i;
	if(A>t)return;
	ll cur=t-max(i*i,A),mov=max(i*i,A)-i*i;
	for(ll h=i;;h++){
		ll z=h*h+h;
		int p=upper_bound(a+1,a+N+1,z-i*i-mov)-a;
		if(p>N){
			printf("%lld\n",mov+i*i-A);
			exit(0);
		}
		cur=min(cur,z-a[p-1]-i*i-mov);
		ll pos=a[p]+i*i+mov;
		if(pos<(ll)(h+1)*(h+1)){
			ll g=(h+1)*(h+1)-pos;;
			mov+=g,cur-=g;
			if(cur<0){
				return;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(N==0||a[N]!=x)a[++N]=x;
	}
	A=a[1];
	for(int i=N;i;i--)a[i]-=a[1];
	for(ll i=1;;i++)sol(i);
}