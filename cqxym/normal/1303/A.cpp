#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	string s;
	cin>>s;
	int f=-1,l=-1,ct=0,len=s.length();
	for(R i=0;i!=len;i++){
		if(s[i]=='1'){
			ct++;
			f=f<0?i:f;
			l=i;
		}
	}
	printf("%d\n",ct==0?0:l-f+1-ct);
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}