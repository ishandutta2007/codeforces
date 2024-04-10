#include<bits/stdc++.h>
using namespace std;
int n,m,a[300003][8];
int can[256];
pair<int,int>check(int x){
	memset(can,0,sizeof(can));
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=0;j<m;j++)
			c=c*2+(a[i][j]>=x);
		can[c]=i;
	} 
	for(int i=0;i<pow(2,m);i++)
		for(int j=0;j<pow(2,m);j++)
			if((i|j)==pow(2,m)-1&&can[i]&&can[j])
				return make_pair(can[i],can[j]);
	return make_pair(-1,0);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	int l=0,r=2147483647;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid).first==-1)
			r=mid-1;
		else
			l=mid;
		if(check(r).first==-1)r--;
		if(check(l+1).first!=-1)l++;
	}
	cout<<check(l).first<<' '<<check(r).second;
}