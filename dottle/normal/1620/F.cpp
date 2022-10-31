#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n,a[N];
int ty[2][N];

int calc(int a,int b,int c){
	if(a>b)swap(a,b);
	if(c>=b)return a;
	if(c>=a)return b;
	return n+1;
}

void print(int k,int p){
	if(p>1)print(ty[k][p],p-1);
	cout<<(k?-a[p]:a[p])<<' ';
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int A=-n,B=-n;
	for(int i=2;i<=n;i++){
		int x=A,y=B;
		if(calc(x,a[i-1],a[i])<calc(y,-a[i-1],a[i]))
			A=calc(x,a[i-1],a[i]),ty[0][i]=0;
		else 
			A=calc(y,-a[i-1],a[i]),ty[0][i]=1;
		if(calc(x,a[i-1],-a[i])<calc(y,-a[i-1],-a[i]))
			B=calc(x,a[i-1],-a[i]),ty[1][i]=0;
		else 
			B=calc(y,-a[i-1],-a[i]),ty[1][i]=1;
	}
	if(min(A,B)==n+1){
		cout<<"NO"<<endl;
		return;
	}
	else cout<<"YES"<<endl;
	if(A!=n+1)print(0,n);
	else print(1,n); 
	cout<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}