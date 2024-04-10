#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,u[200005],v[200005],first[100005],nxt[200005],du[100005],flag=1;
signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		du[u[i]]++,du[v[i]]++;
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=1;i<=n;i++)
		if (du[i]==2)flag=0;
	if (flag==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}