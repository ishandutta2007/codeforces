#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int t[maxn],s[maxn];
stack <int > stk;
int sl;
int ans;
int spd;
bool o=1;
int ntbf=0;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i];
		if(t[i]==1||t[i]==3) cin>>s[i];
		if(t[i]==1){
			spd=s[i];
			
		}
		if(t[i]==2){
			ans+=ntbf;
			ntbf=0;
		}
		if(t[i]==3){
			stk.push(s[i]);
		}
		if(t[i]==4){
			ntbf=0;
		}
		if(t[i]==5){
			while(!stk.empty()) stk.pop();
			sl=0;
		}
		if(t[i]==6){
			ntbf++;
		}
		//cout<<ans<<endl;
		while(!stk.empty()){
			if(stk.top()>=spd) break;
			stk.pop();
			sl--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}