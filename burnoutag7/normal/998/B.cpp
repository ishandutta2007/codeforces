/******************
*  Writer: BD747  *
******************/
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

#define MP make_pair

priority_queue<int> pq;
int n,b,ans;
int a[105],o[105],e[105];
bool c[105];//Can cut between i and i+1 !!!IMPORTANT!!!

int ab(int x){
	if(x>0){
		return x;
	}else{
		return -x;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2){
			o[i]++;
		}else{
			e[i]++;
		}
		o[i]+=o[i-1];
		e[i]+=e[i-1];
	}
	
	for(int i=1;i<n;i++){
		if(o[i]==e[i]){
			c[i]=true;
			pq.push(-ab(a[i+1]-a[i]));
		}
	}
	
	while(b>0 && !pq.empty()){
		int cur=-pq.top();
		pq.pop();
		if(b>=cur){
			b-=cur;
			ans++;
		}else{
			break;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}