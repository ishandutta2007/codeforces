#include<bits/stdc++.h>
using namespace std;
int n,a[103],k,lead;
bool vis[103];
int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++)
		cin>>a[i];
	for(int i=0;i<k;i++){
		lead=(a[i]+lead)%(n-i);
	//	cout<<lead<<' ';
		for(int j=0,cntt=0;j<n;j++){
			cntt+=(1-vis[j]);
			if(cntt==lead+1){
				cout<<j+1<<' ';
				vis[j]=1;
				break;
			}
		}
	}
}