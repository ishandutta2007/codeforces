#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,d,ord[100005],m;
string S;
ll X[100005],Y[100005];
vector<ll>allx,ally;
bool cmp(int A,int B){
	return X[A]<X[B];
}
int bit[100005],f[100005];
void upd(int i,int x){
	for(;i;i-=i&-i)bit[i]=max(bit[i],x);
}
int qry(int i){
	int ret=0;
	for(;i<=m;i+=i&-i)ret=max(ret,bit[i]);
	return ret;
}
int main(){
	scanf("%d",&n);++n;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	for(int i=1;i<=n;i++){
		int x,y;
		if(i<n)scanf("%d%d",&x,&y);
		else x=y=0;
		X[i]=(ll)b*y-(ll)a*x,allx.push_back(X[i]);
		Y[i]=(ll)c*x-(ll)d*y,ally.push_back(Y[i]);
		ord[i]=i;
	}
	sort(allx.begin(),allx.end()),allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end()),ally.erase(unique(ally.begin(),ally.end()),ally.end());
	m=ally.size();
	for(int i=1;i<=n;i++){
		X[i]=lower_bound(allx.begin(),allx.end(),X[i])-allx.begin()+1;
		Y[i]=lower_bound(ally.begin(),ally.end(),Y[i])-ally.begin()+1;
	}
	sort(ord+1,ord+n+1,cmp);
	for(int i=n,j;i;i=j){
		for(j=i;j&&X[ord[j]]==X[ord[i]];j--)
			f[ord[j]]=qry(Y[ord[j]]+1)+1;
		for(int k=j+1;k<=i;k++)
			upd(Y[ord[k]],f[ord[k]]);
	}
	printf("%d",f[n]-1);
}