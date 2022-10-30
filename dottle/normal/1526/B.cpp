#include<bits/stdc++.h>
const int N=100005; 
using namespace std;

int x;
int f[N];

void init(){
	f[0]=1;
	for(int i=0;i<N/2;i++)
		if(f[i])
			f[i+11]=f[i+111]=1;
}

bool solve(){
	cin>>x;
	if(x>11*111)return 1;
	return f[x];
} 

int main(){
	ios::sync_with_stdio(false);
	int t;
	init();
	cin>>t;
	while(t--)cout<<(solve()?"YES":"NO")<<endl;
}