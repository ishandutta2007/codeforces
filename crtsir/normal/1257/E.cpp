#include<bits/stdc++.h>
using namespace std;
int cntr[3],cntl[3],a,b,c,ans,k,gt[200003];
int main(){
	cin>>a>>b>>c;
	int n=a+b+c;
	for(int i=0;i<a;i++){
		int x;
		cin>>x;
		gt[x-1]=0;
		ans++;
	}
	for(int i=0;i<b;i++){
		int x;
		cin>>x;
		gt[x-1]=1;
		ans++;
	}
	for(int i=0;i<c;i++){
		int x;
		cin>>x;
		gt[x-1]=2;
	}
	for(int i=0;i<n;i++)
		cntr[gt[i]]++;
	for(int i=0;i<n;i++){
		cntr[gt[i]]--;cntl[gt[i]]++;
		k=max(k,cntl[0]-cntl[1]);
		ans=min(ans,cntr[0]+cntr[1]+cntl[2]+cntl[0]-k);
	}
	cout<<ans;
}