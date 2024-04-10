#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,m;
	cin>>n>>m;
	short tagR=0,tagW=0,d;
	for(R i=0;i!=n;i++){
		string s;
		cin>>s;
		for(R j=0;j!=m;j++){
			d=1<<((i^j)&1);
			if(s[j]=='R'){
				tagR|=d;
			}else if(s[j]=='W'){
				tagW|=d;
			} 
		}
	}
	if(tagR==3||tagW==3||(tagR&tagW)!=0){
		cout<<"No"<<endl;
		return;
	}
	if(tagR==0&&tagW!=0){
		tagR=tagW^3;
	}else if(tagW==0&&tagR!=0){
		tagW=tagR^3;
	}else if(tagR==0&&tagW==0){
		tagR=2;
		tagW=0;
	}
	tagR>>=1;
	tagW>>=1;
	cout<<"Yes"<<endl;
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			d=(i^j)&1;
			if(d==tagW){
				cout<<'W';
			}else{
				cout<<'R';
			}
		}
		cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}