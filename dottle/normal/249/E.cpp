#include<bits/stdc++.h>
#define int __int128
const int N=1000005;
using namespace std;

int S(int k){return k*(k+1)/2;}
int S2(int k){return k*(k+1)*(2*k+1)/6;} 

int solve2(int x,int y){
	int ans=S(y*y);
	int p=S2(x)-S2(y);
	return ans+p*y-S(y-1)*(x-y);
}
int solve1(int x,int y){
	int ans=S(x*x);
	int p=S2(y-1)-S2(x-1);
	return ans+p*x+S(x)*(y-x);
}

int calc(int x,int y){
	if(x==y)return S(x*y);
	else if(x<y)return solve1(x,y);
	else return solve2(x,y);
}

void print(int a){
	int k=1e10;
	if(a>=k)printf("...%010lld\n",(long long)(a%k));
	else printf("%lld\n",(long long)a);
}

void read(int&x){
	long long a;cin>>a;x=a;
}

void solve(){
	int a,b,c,d;read(a),read(b),read(c),read(d);
	print(calc(c,d)-calc(c,b-1)-calc(a-1,d)+calc(a-1,b-1));
}

main(){
	int _T=1;read(_T);
	while(_T--)solve();
}