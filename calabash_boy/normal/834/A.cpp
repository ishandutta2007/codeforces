#include<bits/stdc++.h>
using namespace std;
char startc,endc;
int c;
map <char,char> cw;
map<char ,char> ccw;
int main(){
	cw[118] = 60;
	cw[60] = 94;
	cw[94] = 62;
	cw[62] = 118;
	ccw[118]= 62;
	ccw[62] = 94;
	ccw[94]= 60;
	ccw[60] = 118;
	scanf("%c %c",&startc,&endc);
	scanf("%d",&c);
	c%=4;
	bool iscw= false;
	bool isccw = false;
	char temp = startc;
	for (int i = 0;i<c;i++){
		temp = cw[temp];
	} 
	if (temp==endc){
		iscw = true;
	}
	temp = startc;
	for (int i =0;i<c;i++){
		temp = ccw[temp];
	}
	if (temp==endc){
		isccw = true;
	}
	if (iscw==isccw){
		cout<<"undefined"<<endl;
	}else{
		if (iscw){
			cout<<"cw"<<endl;
		}else{
			cout<<"ccw"<<endl;
		}
	}
	return 0;
}