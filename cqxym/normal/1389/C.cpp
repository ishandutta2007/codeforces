#include<iostream>
using namespace std;
#define R register int
#define I inline
I void Min(int&x,int y){
	x=x<y?x:y;
}
string s;
int l;
I int NextPos(int x,char c){
	for(R i=x;i!=l;i++){
		if(s[i]==c){
			return i;
		}
	}
	return l;
}
I int Calc(char a,char b){
	int lt=0,res=0;
	while(true){
		int x=NextPos(lt,a);
		res+=x-lt;
		if(x==l){
			return res;
		}
		lt=x+1;
		x=NextPos(lt,b);
		res+=x-lt;
		if(x==l){
			if(a==b){
				return res;
			}
			return res+1;
		}
		lt=x+1;
	}
}
I void Solve(){
	cin>>s;
	l=s.length();
	int ans=l;
	for(R i=0;i!=10;i++){
		for(R j=0;j!=10;j++){
			Min(ans,Calc(i+'0',j+'0'));
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}