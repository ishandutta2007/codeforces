#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second

const int MOD = 1000000007;


int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		vector<int>v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		if(p==1){
			cout<<(n%2)<<endl;
			continue;
		}
		if(n==1){
			cout<<binpow(p, v[0])<<endl;
			continue;
		}
		int cons=1;
		int po=v[v.size()-1];
		int ans=0;
		bool booly=true;
		for(int i=v.size()-2; i>=0; i--){
			
			if(booly==false){
				break;
			}
			if(cons==0){
				cons=1;
				po=v[i];
				continue;
			}
			
			int val=v[i];
			while(po!=val){
				cons=cons*p;
				po--;
				if(cons>1000000000){
					
					int val1=0;
					for(int j=0; j<=i; j++){
						val1=add(val1, binpow(p, v[j]));
					}
					int val2=mul(cons%MOD, binpow(p, po));
					
					ans=sub(val2, val1);
					booly=false;
					break;
				}
			}
			if(booly==false){
				break;
			}
			cons--;
			
			if(i==0){
				break;
			}
		}
		if(booly==false){
			cout<<ans<<endl;
		}
		else{
			cout<<mul(cons%MOD, binpow(p, po))<<endl;
		}
		
	}
	return 0;
}