#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back


void f(int l, int r){
	if(l==r){
		cout<<"! "<<l<<endl;
		return;
	}
	if(l==r-1){
		cout<<"? "<<l<<" "<<r<<endl;
		int x;
		cin>>x;
		if(x==l){
			cout<<"! "<<r<<endl;
			return;
		}
		else{
			cout<<"! "<<l<<endl;
			return;
		}
	}
	cout<<"? "<<l<<" "<<r<<endl;
	int ind;
	cin>>ind;
	int mid=(l+r)/2;
	if(ind>mid){
		if(mid+1==r){
			f(l, mid);
		}
		else{
			cout<<"? "<<mid+1<<" "<<r<<endl;
			int ind2;
			cin>>ind2;
			if(ind2==ind){
				f(mid+1, r);
			}
			else{
				f(l, mid);
			}
		}
	}
	else{
		cout<<"? "<<l<<" "<<mid<<endl;
		int ind2;
		cin>>ind2;
		if(ind2==ind){
			f(l, mid);
		}
		else{
			f(mid+1, r);
		}
	}
}


 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	f(1, n);
	
	return 0;
}