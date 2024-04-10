#include <iostream>

using namespace std;

int main(){
	int x[6],y[6];
	for(int i=0; i<6; i++){
		cin >> x[i] >> y[i];
	}
	if(x[2]<=x[0]&&x[3]>=x[1]){
		if(y[3]>=y[0]&&y[2]<=y[0]) y[0]=y[3];
		else if(y[2]<=y[1]&&y[3]>=y[1]) y[1]=y[2];
	}
	if(y[2]<=y[0]&&y[3]>=y[1]){
		if(x[3]>=x[0]&&x[2]<=x[0]) x[0]=x[3];
		else if(x[2]<=x[1]&&x[3]>=x[1]) x[1]=x[2];
	}
	if(x[4]<=x[0]&&x[5]>=x[1]){
		if(y[5]>=y[0]&&y[4]<=y[0]) y[0]=y[5];
		else if(y[4]<=y[1]&&y[5]>=y[1]) y[1]=y[4];
	}
	if(y[4]<=y[0]&&y[5]>=y[1]){
		if(x[5]>=x[0]&&x[4]<=x[0]) x[0]=x[5];
		else if(x[4]<=x[1]&&x[5]>=x[1]) x[1]=x[4];
	}
	if(x[1]<=x[0]&&y[1]<=y[0]) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}