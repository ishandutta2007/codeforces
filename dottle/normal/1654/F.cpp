#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

string s;
int nw[N],sa[N],rk[N],sz[N];
int n,M;

void srt(){
	for(int i=0;i<=M;i++)sz[i]=0;
	for(int i=0;i<n;i++)sz[rk[i]]++;
	for(int i=0;i<=M;i++)sz[i]+=sz[i-1];
	for(int i=n-1;i>=0;i--)sa[--sz[rk[nw[i]]]]=nw[i];
}

void solve(){
	cin>>n;
	n=1<<n;
	cin>>s;
	M=200;
	for(int i=0;i<n;i++)
		rk[i]=s[i],nw[i]=i;
	srt();
	for(int w=1,p=0;p<n&&w<n;w<<=1,M=p){
		p=0;
		for(int i=0;i<n;i++)
			nw[p++]=sa[i]^w;
		srt();
		swap(rk,nw);
		rk[sa[0]]=p=1;
		for(int i=1;i<n;i++)
			rk[sa[i]]=(nw[sa[i]]==nw[sa[i-1]]&&nw[sa[i]^w]==nw[sa[i-1]^w])?p:++p;
	}
	for(int i=0;i<n;i++)
		cout<<s[i^sa[0]];
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}