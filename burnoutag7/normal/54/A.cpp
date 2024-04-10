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

int n,k,c,t,cnt;
bool h[400];
int ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>c;
	for(int i=1;i<=c;i++){
		cin>>t;
		h[t]=true;
	}
	
	for(int i=1;i<=n;i++){
		if(h[i]){
			ans++;
			cnt=0;
		}else{
			cnt++;
			if(cnt==k){
				cnt=0;
				ans++;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}