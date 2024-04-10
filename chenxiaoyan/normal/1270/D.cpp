/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
int a[N+1];
int main(){
	cin>>n>>m;
	cout<<"? ";for(int i=1;i<=m;i++)cout<<i<<" ";puts("");
	int x,v;
	cin>>x>>v;
	for(int i=1;i<=m;i++)if(i!=x){
		cout<<"? ";for(int j=1;j<=m;j++)cout<<(j==i?m+1:j)<<" ";puts("");
		int x0,v0;
		cin>>x0>>v0;
		if(v<v0)a[i]=1,a[m+1]=2;
		else if(v>v0)a[i]=2,a[m+1]=1;
	}
	if(a[m+1]){
		for(int i=1;i<=m;i++)if(i!=x&&!a[i])a[i]=a[m+1];
		int cnt=0;
		for(int i=1;i<=m;i++)cnt+=a[i]==1;
		printf("! %d\n",cnt+1);
	}
	else{
		cout<<"? ";for(int i=1;i<=m+1;i++)if(i!=x)cout<<i<<" ";puts("");
		int x0,v0;
		cin>>x0>>v0;
		if(v<v0)printf("! 1\n");
		else printf("! %d\n",m);
	}
	return 0;
}