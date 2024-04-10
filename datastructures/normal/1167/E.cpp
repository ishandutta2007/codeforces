#include <iostream>
#include <cstdio>
#include <vector> 
#define ll long long
using namespace std; 
int n,x,flag,a[1000005],l,r,mx[1000005],mn[1000005];
ll ans;
vector <int>c[1000005];
signed main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++)cin>>a[i],c[a[i]].push_back(i);
	for (int i=1;i<=x;i++){
		flag=1;
		mx[i]=mx[i-1];
		if (!c[i].empty()){
			for (int j=0,len=c[i].size();j<len;j++){
				if (mx[i]>c[i][j]){
					flag=0;
					break;
				}
				else mx[i]=c[i][j];
			}
		}
		if (flag==0)break;
		l++;
	}
	mn[x+1]=n+1,r=x+1;
	for (int i=x;i>=1;i--){
		flag=1;
		mn[i]=mn[i+1];
		if (!c[i].empty()){
			for (int j=c[i].size()-1;j>=0;j--){
				if (mn[i]<c[i][j]){
					flag=0;
					break;
				}
				else mn[i]=c[i][j];
			}
		}
		if (flag==0)break;
		r--;
	}
	for (int i=0;i<=l;i++){
		while(r<=x+1&&(mn[r]<mx[i]||r<=i+1))r++;
		ans+=x+2-r;
	}
	cout<<ans<<endl;
	return 0;
}