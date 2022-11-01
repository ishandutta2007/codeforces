#include<iostream>
using namespace std;
#define R register int
inline int Count(string&s,int x){
	if(x<0||x+3>s.length()){
		return 0;
	}
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
int main(){
	int n,q,cur=0;
	cin>>n>>q;
	string s;
	cin>>s;
	for(R i=0;i!=n;i++){
		cur+=Count(s,i);
	}
	for(R i=0;i!=q;i++){
		int pos;
		cin>>pos;
		pos--;
		char c;
		cin>>c;
		for(R j=-2;j!=1;j++){
			cur-=Count(s,j+pos);
		}
		s[pos]=c;
		for(R j=-2;j!=1;j++){
			cur+=Count(s,j+pos);
		}
		cout<<cur<<endl;
	}
	return 0;
}