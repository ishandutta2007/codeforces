#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=7005;
const int M=1e5+5;


bitset<N>mo[N];
bitset<N>di[N];
bitset<N>ms[M];


int mob[N];

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mob[1]=1;
	for(int i=2; i<N; i++){
		int val=i;
		vector<int>vec;
		for(int j=2; j*j<=val; j++){
			while(val%j==0){
				vec.pb(j);
				val=val/j;
			}
		}
		if(val!=1){
			vec.pb(val);
		}
		int sz=vec.size();
		bool che=1;
		for(int j=1; j<sz; j++){
			if(vec[j]==vec[j-1]){
				che=0;
				break;
			}
		}
		if(che){
			mob[i]=1;
		}
	}
	for(int i=1; i<N; i++){
		for(int j=1; j*i<N; j++){
			if(mob[j]){
				mo[i][i*j]=1;
			}
		}
	}
	
	for(int i=1; i<N; i++){
		for(int j=1; j*j<=i; j++){
			if(i%j==0){
				di[i][j]=1;
				di[i][i/j]=1;
			}
		}
	}
	
	int n, q;
	cin>>n>>q;
	
	while(q--){
		int ty;
		cin>>ty;
		if(ty==1){
			int x, v;
			cin>>x>>v;
			ms[x]=di[v];
		}
		else if(ty==2){
			int x, y, z;
			cin>>x>>y>>z;
			ms[x]=ms[y]^ms[z];
		}
		else if(ty==3){
			int x, y, z;
			cin>>x>>y>>z;
			ms[x]=(ms[y]&ms[z]);
		}
		else{
			int x, v;
			cin>>x>>v;
			cout<<((ms[x]&mo[v]).count())%2;
		}
	}
	
	return 0;
}