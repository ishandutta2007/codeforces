/*








*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int a[N+1],ans[N+1];
int ord[N+1];
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)ord[i]=i,cin>>a[i];
	sort(ord+1,ord+n+1,cmp);
	int las=0,sum=0;
	for(int i=1;i<=n;i++){
		int o=ord[i];
		ans[o]=max(las,(a[o]+1)/2);
//		printf("ans[%d]=%d\n",o,ans[o]);
		if(ans[o]>a[o])return puts("-1"),0;
		las=ans[o];sum+=ans[o];
	}
	if(sum>m)return puts("-1"),0;
	for(int i=n;i;i--){
		int o=ord[i];
//		cout<<sum+a[o]-ans[o]<<"\n";
		if(sum+a[o]-ans[o]<m)sum+=a[o]-ans[o],ans[o]=a[o];
		else{ans[o]+=m-sum;break;}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}