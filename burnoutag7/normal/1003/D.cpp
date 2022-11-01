#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int func(int x){
	int res=0;
	while(x!=1){
		x/=2;
		res++;
	}
	return res;
}
int n,q,t;
int coi[45];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t;
		coi[func(t)]++;
	}
	for(int time=1;time<=q;time++){
		int clo[45];
		memcpy(clo,coi,sizeof(coi));
		cin>>t;
		long long ans=0;
		for(int i=30;i>=0;i--){
			if(t>=(1<<i)&&clo[i]){
				int b=1<<i;
				int a=min(clo[i],t/b);
				t-=a*b;
				clo[i]-=a;
				ans+=a;
			}
		}
		if(t) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}