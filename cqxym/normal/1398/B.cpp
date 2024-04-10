#include<iostream>
#include<queue>
using namespace std;
#define R register int
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length(),l1=0,l2,ans=0;
	priority_queue<int>Q;
	while(l1!=l){
		for(l2=l1+1;l2!=l&&s[l2]==s[l1];l2++);
		if(s[l1]=='1'){
			Q.push(l2-l1);
		}
		l1=l2;
	}
	while(Q.size()>1){
		ans+=Q.top();
		Q.pop();
		Q.pop();
	}
	if(Q.empty()==false){
		ans+=Q.top();
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}