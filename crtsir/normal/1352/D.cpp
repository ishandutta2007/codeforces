#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,a[1003]; 
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		int lst=0,ans=0,A=0,B=0;
		for(int i=0,j=n-1;i<=j;){
			int cnt=0;ans++;
			for(;i<=j;i++){
				if(lst<cnt)break;
				A+=a[i];cnt+=a[i];
			}if(i>j)break;
			ans++;lst=cnt;cnt=0;
			for(;i<=j;j--){
				if(lst<cnt)break;
				B+=a[j];cnt+=a[j];
			}lst=cnt;
		}cout<<ans<<' '<<A<<' '<<B<<endl;
	} 
}