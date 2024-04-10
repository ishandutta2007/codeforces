#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	string s,t="";
	cin>>s;
	int len=s.length(),pos=0,ct;
	t+=s[0];
	for(R i=1;i!=len;i++){
		if(pos>0&&pos+1<t.length()){
			if(t[pos-1]==s[i]){
				pos--;
			}else if(t[pos+1]==s[i]){
				pos++;
			}else{
				puts("NO");
				return;
			}
		}else if(pos==0){
			if(t.length()>1&&t[1]==s[i]){
				pos=1;
			}else{
				t=s[i]+t;
			}
		}else{
			if(t.length()>1&&t[pos-1]==s[i]){
				pos--;
			}else{
				t+=s[i];
				pos++;
			}
		}
	}
	len=t.length();
	for(R i=0;i!=26;i++){
		ct=0;
		for(R j=0;j!=len;j++){
			if(t[j]==i+'a'){
				ct++;
			}
		}
		if(ct==0){
			t+=i+'a';
		}else if(ct!=1){
			puts("NO");
			return;
		}
	}
	puts("YES");
	cout<<t<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}