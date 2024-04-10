#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(long long int i=0; i<a; i++)
 
using namespace std;

int main(){
	ll n,k;
	cin >> n >> k;
	ll a[n];
	loop(n){
		cin >> a[i];
	}
	sort(a,a+n);
	ll Min,Max,moves,it,ans;
	if(n%2==0){
		Min=0;
		Max=n/2-1;
		while(Min!=Max){
			it=(Min+Max-1)/2;
			moves=0;
			loop(n){
				if(i<n/2-it-1) moves=moves+a[n/2-it-1]-a[i];
				else if(i>n/2+it) moves=moves+a[i]-a[n/2+it];
			}
			if(k<moves) Min=it+1;
			else Max=it;
		}
		moves=0;
		loop(n){
			if(i<n/2-Min-1) moves=moves+a[n/2-Min-1]-a[i];
			else if(i>n/2+Min) moves=moves+a[i]-a[n/2+Min];
		}
		ans=a[n/2+Min]-a[n/2-Min-1]-(k-moves)/(n/2-Min);
		if(ans<0) ans=0;
	}
	if(n%2==1){
		Min=0;
		Max=n/2;
		while(Min!=Max){
			it=(Min+Max-1)/2;
			moves=0;
			loop(n){
				if(i<n/2-it) moves=moves+a[n/2-it]-a[i];
				else if(i>n/2+it) moves=moves+a[i]-a[n/2+it];
			}
			if(k<moves) Min=it+1;
			else Max=it;
		}
		moves=0;
		loop(n){
			if(i<n/2-Min) moves=moves+a[n/2-Min]-a[i];
			else if(i>n/2+Min) moves=moves+a[i]-a[n/2+Min];
		}
		ans=a[n/2+Min]-a[n/2-Min]-(k-moves)/(n/2+1-Min);
		if(ans<0) ans=0;
	}
	cout << ans << endl;
	return 0;
}