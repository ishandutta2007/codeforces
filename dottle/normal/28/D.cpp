#include<bits/stdc++.h>
const int N=200400;
using namespace std;

int f[N],pr[N],ln[N];
int n,ans;
map<vector<int>,int> a;

void print(int k){
	if(!k)return;
	print(pr[k]),cout<<k<<' ';
}

bool chk(int r,int c,int l){
	if(r+c>N)return 1;
	return l&&a.find({l,r+c})==a.end(); 
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int v,c,l,r;
		cin>>v>>c>>l>>r;
		if(chk(r,c,l))continue;
		int nw=a[{l,c+r}];
		ln[i]=ln[nw]+1,f[i]=f[nw]+v,pr[i]=nw;
		if(!r&&f[i]>f[ans])ans=i;
		if(f[i]>f[a[{l+c,r}]])a[{l+c,r}]=i;
	} 
	cout<<ln[ans]<<endl;
	print(ans);
}