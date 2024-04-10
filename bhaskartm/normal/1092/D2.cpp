#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main() {
	int n;
	cin>>n;
	int arr[n+1];
	int l[n+1];
	int r[n+1];
	arr[0]=0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	l[1]=1;
	for(int i=2; i<=n; i++){
		if(arr[i]==arr[i-1]){
			l[i]=l[i-1];
		}
		else{
			l[i]=i;
		}
	}
	r[n]=n;
	for(int i=n-1; i>=0; i--){
		if(arr[i]==arr[i+1]){
			r[i]=r[i+1];
		}
		else{
			r[i]=i;
		}
	}
	set<pair<int, pair<int, int>>>se;
	if(r[1]==n){
		cout<<"YES"<<endl;
		return 0;
	}
	se.insert({arr[1], {r[1], 1}});
	for(int i=2; i<=n; i++){
		if(arr[i]==arr[i-1]){
			continue;
		}
		se.insert({arr[i], {r[i]-i+1, i}});
	}
	
	while(se.size()>=1){
		
		
		if(se.size()==1){
			cout<<"YES";
			return 0;
		}
		auto it=se.begin();
		int le=(*it).s.s;
		int val=(*it).f;
		int len=(*it).s.f;
		int ri=le+len-1;
		if(len%2==1){
			cout<<"NO";
			return 0;
		}
		if(le==1){
			int val2=arr[ri+1];
			int len2=r[ri+1]-(ri+1)+1;
			se.erase({val, {len, le}});
			se.erase({val2, {len2, ri+1}});
			se.insert({val2, {len+len2, le}});
			r[1]=len+len2;
			l[len+len2]=1;
			continue;
		}
		if(ri==n){
			int val2=arr[le-1];
			int len2=le-1-l[le-1]+1;
			se.erase({val, {len, le}});
			se.erase({val2, {len2, l[le-1]}});
			se.insert({val2, {len+len2, l[le-1]}});
			l[n]=n-len-len2+1;
			r[n-len-len2+1]=n;
			continue;
		}
		int vall=arr[le-1];
		int valr=arr[ri+1];
		if(vall==valr){
			int lll=l[le-1];
			int rrr=r[ri+1];
			se.erase({val, {len, le}});
			se.erase({vall, {le-1-lll+1, lll}});
			se.erase({valr, {rrr-(ri+1)+1, ri+1}});
			se.insert({vall, {rrr-lll+1, lll}});
			r[lll]=rrr;
			l[rrr]=lll;
			continue;
		}
		if(vall>valr){
			
			int rrr=r[ri+1];
			se.erase({val, {len, le}});
			se.erase({valr, {rrr-(ri+1)+1 ,ri+1}});
			se.insert({valr, {rrr-le+1, le}});
			l[rrr]=le;
			r[le]=rrr;
			continue;
		}
		if(vall<valr){
			int lll=l[le-1];
			se.erase({val, {len, le}});
			se.erase({vall, {le-1-lll+1, lll}});
			se.insert({vall, {ri-lll+1, lll}});
			r[lll]=ri;
			l[ri]=lll;
		}
	}
	return 0;
}