#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

int f(int num){
	if(num>=0){
		return (num+1)/2;
	}
	else{
		return (num/2);
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int b[n];
	int c[n];
	for(int i=0; i<n; i++){
		b[i]=0;
	}
	for(int i=0; i<n; i++){
		c[i]=arr[i];
	}
	if(n==1){
		int q;
		cin>>q;
		int sum=arr[0];
		cout<<f(sum)<<endl;
		while(q--){
			int l, r, x;
			cin>>l>>r>>x;
			sum+=x;
			cout<<f(sum)<<endl;
		}
		return 0;
	}
	int dif[n-1];
	for(int i=0; i<n-1; i++){
		dif[i]=arr[i+1]-arr[i];
	}
	for(int i=1; i<n; i++){
		b[i]+=(b[i-1]);
		c[i]-=b[i];
		if(c[i]>c[i-1]){
			b[i]+=(c[i]-c[i-1]);
			c[i]=c[i-1];
		}
	}
	int sum=b[n-1]+c[0];
	cout<<f(sum)<<endl;
	int q;
	cin>>q;
	while(q--){
		int l, r, x;
		cin>>l>>r>>x;
		if(l==1 && r==n){
			sum+=x;
			cout<<f(sum)<<endl;
			continue;
		}
		if(l==1){
			sum+=x;
			r--;
			int old=dif[r];
			int ne=dif[r]-x;
			int inc=0;
			if(old>0){
				inc-=(old);
			}
			if(ne>0){
				inc+=ne;
			}
			sum+=inc;
			dif[r]=ne;
			cout<<f(sum)<<endl;
			continue;
		}
		if(r==n){
			l--;
			int old=dif[l-1];
			int ne=old+x;
			int inc=0;
			if(old>0){
				inc-=old;
			}
			if(ne>0){
				inc+=ne;
			}
			sum+=inc;
			dif[l-1]=ne;
			cout<<f(sum)<<endl;
			continue;
		}
		else{
			r--;
			l--;
			int old1=dif[r];
			int ne1=dif[r]-x;
		
			int old2=dif[l-1];
			int ne2=dif[l-1]+x;
			int inc=0;
			if(old1>0){
				inc-=old1;
			}
			if(old2>0){
				inc-=old2;
			}
			if(ne1>0){
				inc+=ne1;
			}
			if(ne2>0){
				inc+=ne2;
			}
			sum+=inc;
			dif[l-1]=ne2;
			dif[r]=ne1;
			cout<<f(sum)<<endl;
			continue;
		}
	}
	return 0;
}