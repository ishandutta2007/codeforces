#include<iostream>
using namespace std;
#define R register int
int c[200001][26];
int main(){
	string s;
	cin>>s;
	int l,r,q,len=s.length(),ct;
	for(R i=0;i!=len;i++){
		for(R j=0;j!=26;j++){
			c[i+1][j]=c[i][j];
		}
		c[i+1][s[i]-'a']++;
	}
	/*for(R i=0;i<=len;i++){
		for(R j=0;j<3;j++){
			printf("%d ",c[i][j]);
		}
		puts("");
	}*/
	cin>>q;
	for(R i=0;i!=q;i++){
		cin>>l>>r;
		if(l==r){
			cout<<"Yes"<<endl;
		}else{
			ct=0;
			for(R j=0;j!=26;j++){
				if(c[r][j]-c[l-1][j]==0){
					ct++;
				}
			}
			/*if(ct==25){
				cout<<"No"<<endl;
			}else{
				cout<<"Yes"<<endl;
			}*/
			if(s[l-1]==s[r-1]){
				if(ct>23){
					cout<<"No"<<endl;
				}else{
					cout<<"Yes"<<endl;
				}
			}else if(ct==25){
				cout<<"No"<<endl;
			}else{
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;
}