#include<iostream>
using namespace std; 
#define R register int
inline bool Equal(char a,char b){
	if(a=='?'||b=='?'){
		return true;
	}
	return a==b;
}
inline void Solve(){
	string s;
	int n,k;
	cin>>n>>k;
	cin>>s;
	for(R i=0;i!=k;i++){
		char tem='?';
		for(R j=i;j<n;j+=k){
			if(Equal(tem,s[j])==false){
				puts("NO");
				return;
			}
			if(tem=='?'){
				tem=s[j];
			}else{
				s[j]=tem;
			}
		}
	}
	for(R i=0;i!=k;i++){
		char tem='?';
		for(R j=n-1-i;j>=0;j-=k){
			if(Equal(tem,s[j])==false){
				puts("NO");
				return;
			}
			if(tem=='?'){
				tem=s[j];
			}else{
				s[j]=tem;
			}
		}
	}
	int s1=0,s2=0;
	for(R i=0;i!=k;i++){
		if(s[i]=='0'){
			s1++;
		}else if(s[i]=='1'){
			s2++;
		}
	}
	if(s1>k>>1||s2>k>>1){
		puts("NO");
	}else{
		puts("YES");
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}