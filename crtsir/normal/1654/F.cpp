#include<bits/stdc++.h>
using namespace std;
int n,rnk[262144],idx[262144],nw,tmp[262144];string s;
bool cmp(int x,int y){
	return make_pair(rnk[x],rnk[x^(1<<nw)])<make_pair(rnk[y],rnk[y^(1<<nw)]);
}
int main(){
	cin>>n>>s;
	for(int i=0;i<(1<<n);i++)
		rnk[i]=s[i]-'a',idx[i]=i;
	for(int i=0;i<n;i++){nw=i;
		sort(idx,idx+(1<<n),cmp);
		tmp[idx[0]]=0;
		int k=0;
		for(int j=1;j<(1<<n);j++){
			if(rnk[idx[j]]!=rnk[idx[j-1]]||rnk[idx[j]^(1<<i)]!=rnk[idx[j-1]^(1<<i)])
				k++;
			tmp[idx[j]]=k;
		}
		for(int j=0;j<(1<<n);j++)
			rnk[j]=tmp[j];
	}
	for(int i=0;i<(1<<n);i++)
		cout<<s[idx[0]^i];
}