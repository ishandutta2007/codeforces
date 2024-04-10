#include<iostream>
using namespace std;
#define R register int
int a[50];
bool tag[50];
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length();
	for(R i=0;i!=l;i++){
		a[i]=s[i]-'A';
	}
	for(R i=0;i!=8;i++){
		for(R j=0;j!=l;j++){
			if((i>>a[j]&1)==1){
				tag[j]=true;
			}else{
				tag[j]=false;
			}
		}
		int Top=0;
		bool f=true;
		for(R j=0;j!=l;j++){
			if(tag[j]==true){
				Top++;
			}else{
				if(Top==0){
					f=false;
					break;
				}
				Top--;
			}
		}
		if(f==true&&Top==0){
			puts("YES");
			return;
		}
	}
	puts("No");
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}