#include<bits/stdc++.h>
#define int long long
#define lxl __int128
const int N=1000005,MX=1e18;
using namespace std;

vector<int> A;
void dfs(int k,int d){
	if(k>MX)return;
	A.push_back(k);
	dfs(k+4*d,d*10);
	dfs(k+7*d,d*10);
}

void init(){
	dfs(4,10),dfs(7,10);
	sort(A.begin(),A.end());
}

struct node{int l,r;}a[N];
int n,k,m,len=MX;
lxl L[N],R[N];

bool check(int l,int r){
	if(A[r]-A[l]>len)return 0;
	if(R[r]+L[l]>k)return 0;
	return 1;
}

void solve(){
	init();
	cin>>n>>k;
	m=A.size();
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r,len=min(len,a[i].r-a[i].l);
	sort(a+1,a+1+n,[](node x,node y){return x.r<y.r;});
	lxl sum=0,num=0;
	for(int i=0,nw=1;i<m;i++){
		while(nw<=n&&a[nw].r<=A[i])num++,sum+=a[nw].r,nw++;
		R[i]=num*A[i]-sum;
	}
	sort(a+1,a+1+n,[](node x,node y){return x.l>y.l;});
	sum=0,num=0;
	for(int i=m-1,nw=1;i>=0;i--){
		while(nw<=n&&a[nw].l>=A[i])num++,sum+=MX-a[nw].l,nw++;
		L[i]=num*(MX-A[i])-sum;
	}
	int ans=0;
	for(int l=0,r=-1;l<m;l++){
		while(r+1!=m&&check(l,r+1))r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}