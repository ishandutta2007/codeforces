#include<iostream>
using namespace std;
#define R register int
char m[21];
inline void Min(char&x,char&y){
	x=x<y?x:y;
}
inline void Solve(){
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(R i=0;i!=20;i++){
		m[i]='z';
	}
	for(R i=0;i!=n;i++){
		if(t[i]<s[i]){
			puts("-1");
			return;
		}else if(s[i]<t[i]){
			Min(m[s[i]-'a'],t[i]); 
		}
	}
	int ans=0;
	for(R i=0;i!=20;i++){
		bool tag=false;
		for(R j=0;j!=n;j++){
			if(s[j]<t[j]&&s[j]==i+'a'){
				s[j]=m[s[j]-'a'];
				tag=true;
				if(s[j]<t[j]){
					Min(m[s[j]-'a'],t[j]);
				}
			}
		}
		ans+=tag;
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