#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

 main() {
	int n, x;
	cin>>n>>x;
	int d[2*n];
	for(int i=0; i<n; i++){
		cin>>d[i];
	}
	for(int i=n; i<2*n; i++){
		d[i]=d[i-n];
	}
	int l=0;
	int r=0;
	int curr=1;
	int val=d[0];
	int maxi=0;
	
	while(l<n){
		
		while(r+1<2*n && d[r+1]+curr<=x){
			curr+=d[r+1];
			val=val+((d[r+1])*(d[r+1]+1))/2;
			r++;
		}
		
		int num=x-curr;
		int val2=(num*(num+1))/2;
		maxi=max(maxi, val+val2);
		
		if(r>l){
			val-=((d[l+1]*(d[l+1]+1))/2);
			val-=d[l];
			val+=d[l+1];
			curr-=d[l+1];
			l++;
		}
		else{
			val-=d[l];
			val+=d[l+1];
			l++;
			r=l;
			curr=1;
		}
		
	}
	
	l=2*n;
	r=2*n-1;
	val=0;
	curr=0;
	while(r>=n){
		while(l-1>=0 && d[l-1]+curr<=x){
			val+=((d[l-1]+1)*(d[l-1]))/2;
			curr+=d[l-1];
			l--;
		}
		int num=x-curr;
		int val2=((d[l-1]+d[l-1]-num+1)*(num))/2;
		maxi=max(maxi, val+val2);
		
		int z=0;
		val=max(z, val-((d[r])*(d[r]+1))/2);
		curr=max(z, curr-d[r]);
		r--;
		l=min(l, r+1);
		
	}
	
	cout<<maxi;
	return 0;
}