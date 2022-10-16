#include<bits/stdc++.h>
using namespace std;
int small[300003],big[300003],val[600003],x[600003],tot,last[300003];
void ch(int p,int a){
	for(;p<=tot;p+=(p&(-p)))val[p]+=a;
}
int fi(int p){
	int ret=0;
	for(;p;p-=(p&(-p)))ret+=val[p];
	return ret;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)small[i]=i,big[i]=i,x[n-tot++]=i;
	for(int i=0;i<m;i++){
		int a;cin>>a;
		x[++tot]=a;
		small[a]=1;
	}
	for(int i=1;i<=tot;i++){
		if(last[x[i]])
			big[x[i]]=max(big[x[i]],fi(i)-fi(last[x[i]]-1)),
			ch(last[x[i]],-1);
		ch(i,1);
		last[x[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(last[i])big[i]=max(big[i],fi(tot)-fi(last[i]-1));
		cout<<small[i]<<' '<<big[i]<<endl;
	}
}