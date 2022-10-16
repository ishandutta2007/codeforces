#include<bits/stdc++.h>
#include<set>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m,n,k,x=1,y=1;
	cin>>m>>n>>k;
	int a[k+1],b[1+k],maxv=0;
	for(int i=1;i<=k;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			int minv=4000;
			for(int l=1;l<=k;l++)
				if(fabs(i-a[l])+fabs(j-b[l])<minv)
					minv=fabs(i-a[l])+fabs(j-b[l]);
			if(maxv<minv){
				maxv=minv;
				x=i;
				y=j;
			}
		}
	cout<<x<<' '<<y;
}