#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const int N=1e6+5;
bool pos[N];
bool vis[N];
int tot=0;

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k, l, r, t, x, y;
	cin>>k>>l>>r>>t>>x>>y;
	k-=l;
	r-=l;
	l=0;
	
	int pos=k;
	if(y<=x){
		if(k+y<=r){
			pos+=y;
		}
		int red=pos+1;
		if(x==y){
			if(x>=red){
				cout<<"No";
				return 0;
			}
			else{
				cout<<"Yes";
				return 0;
			}
		}
		if((log10(t-1) + log10(x-y))>=19 || (t-1)*(x-y)+x>=red){
			cout<<"No";
			return 0;
		}
		else{
			cout<<"Yes";
			return 0;
		}
	}
	
	int maxi=r-y;
	if(maxi>=(x-1)){
		cout<<"Yes";
		return 0;
	}
	
	if(k<x && k>maxi){
		cout<<"No";
		return 0;
	}
	
	if(pos+y<=r){
		pos+=y;
		
	}
	
	while(1){
		int num=((pos-x)/x)+1;
		
		tot+=num;
		pos-=num*x;
		
		if(vis[pos]){
			cout<<"Yes";
			return 0;
		}
		
		vis[pos]=1;
		if(pos>maxi){
			if(tot+1>t){
				cout<<"Yes";
				return 0;
			}
			else{
				cout<<"No";
				return 0;
			}
		}
		pos+=y;
		
	}
	
	return 0;
}