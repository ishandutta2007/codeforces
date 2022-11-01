#include<iostream>
#include<stack>
using namespace std;
#define R register int
inline void Solve(){
	int n;
	cin>>n;
	string s,t1="",t2="";
	cin>>s;
	if((n&1)==1||s[0]=='0'||s[n-1]=='0'){
		cout<<"No"<<endl;
		return;
	}
	int ct1=0,g1=0,g0=0;
	for(R i=0;i!=n;i++){
		if(s[i]=='1'){
			ct1++;
		}
	}
	if((ct1&1)==1){
		cout<<"no"<<endl;
		return;
	}
	for(R i=0;i!=n;i++){
		if(s[i]=='1'){
			g1++;
			if((g1<<1)<=ct1){
				t1+='(';
				t2+='(';
			}else{
				t1+=')';
				t2+=')';
			}
		}else{
			g0++;
			if((g0&1)==0){
				t1+=')';
				t2+='(';
			}else{
				t1+='(';
				t2+=')';
			}
		}
	}
	cout<<"YES"<<endl<<t1<<endl<<t2<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}