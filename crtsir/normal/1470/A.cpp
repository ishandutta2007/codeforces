#include<bits/stdc++.h>
using namespace std;
int T,n,m,k[300003],c[300003];
bool cmp(int x,int y){return x>y;}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			scanf("%d",k+i);
			k[i]--;
		}
		for(int i=0;i<m;i++)
			scanf("%d",c+i);
		sort(k,k+n,cmp);
		long long ans=0;
		for(int i=0,cnt=0;i<n;i++)
			if(k[i]>cnt){
				ans+=c[cnt];
				cnt++;
			}else
				ans+=c[k[i]];
		cout<<ans<<endl;
	}
}