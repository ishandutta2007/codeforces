#include<bits/stdc++.h>
using namespace std;
int n,a[1000003],lg[1000003]; 
int mp[2][1048576];
int main(){
	cin>>n;
	lg[1]=0;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<1048576;i++)
		mp[0][i]=-2,mp[1][i]=-2;
	int ans=0;
	for(int i=19;i>=0;i--){
		for(int j=0;j<n;j++)
			if(a[j]&(1<<i)){
				int l=j,r=j;
				while(r<n&&(a[r]&(1<<i)))r++;
				r--;
				mp[l-1&1][0]=l-1;
				int nw=0; 
				for(register int k=l;k<=r;k++){
					nw^=(a[k]>>i+1);
					if(mp[k&1][nw]==-2)
						mp[k&1][nw]=k;
					else
						ans=max(ans,k-mp[k&1][nw]);
				}nw=0;
				for(register int k=l;k<=r;k++)
					nw^=(a[k]>>i+1), 
					mp[k&1][nw]=-2;
				mp[l-1&1][0]=-2;
				j=r;
			}
	}
	cout<<ans;
}