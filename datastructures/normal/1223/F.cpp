#include <iostream>
#include <cstdio>
#include <map>
#define N 3000005
using namespace std;
int t,n,a[N],f[N],id[N];
map <int,int>c[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=0;i<=n;i++)f[i]=0,id[i]=i,c[i].clear();
		long long ans=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (c[id[i-1]][a[i]]!=0){
				f[i]=f[c[id[i-1]][a[i]]-1]+1;
				id[i]=id[c[id[i-1]][a[i]]-1];  
			} 
			c[id[i]][a[i]]=i;
			ans+=f[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}