#include<iostream>
#include<map>
using namespace std;
#define R register int
map<int,int>C;
inline void Solve(){
	int n,x,ct=0;
	cin>>n>>x;
	string s;
	cin>>s;
	for(R i=0;i!=n;i++){
		if(s[i]==48){
			ct++;
		}else{
			ct--;
		}
	}
	int ans=0,c=0;
	if(x==0&&ct==0){
		puts("-1");
		return;
	}else if(x==0){
		ans=1;
	}
	for(R i=0;i!=n;i++){
		if(s[i]==48){
			c++;
		}else{
			c--;
		}
		int tem=x-c;
		if(ct==0){
			if(x==c){
				puts("-1");
				return;
			}
		}else{
			if(tem%ct==0&&tem/ct>=0){
				ans++;
			}
		}
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