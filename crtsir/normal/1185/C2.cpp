#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,a[200003],cnt2[103];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt+=a[i];
		int tmp=cnt,ans=0;
		if(cnt>m){
			for(int j=100;j>=0;j--)
				if(tmp-cnt2[j]*j<=m)
				{
					ans=ans+(tmp-m-1)/j+1;
					break;
				}
				else
					tmp=tmp-cnt2[j]*j,
					ans+=cnt2[j];
		}
		printf("%d ",ans);
		cnt2[a[i]]++;
	}
}