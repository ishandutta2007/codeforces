#include <iostream>
using namespace std;
int n,tagx,tagy,yes=0;
char str[1001][10];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i];
		if(!yes){
			if(str[i][0]=='O'&&str[i][1]=='O')
			yes=1,tagx=i,tagy=1,str[i][0]='+',str[i][1]='+';
			else if(str[i][3]=='O'&&str[i][4]=='O')
			yes=1,tagx=i,tagy=2,str[i][3]='+',str[i][4]='+';
		}
	}
	if(yes){
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			puts(str[i]);
	}else cout<<"NO"<<endl;
	return 0;
}