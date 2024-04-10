#include<bits/stdc++.h>

using namespace std;

const int maxn=10005;

char x[maxn];
bool ck[5];
int l;

int main(){
	cin>>x;
	while(x[l]) l++;
	if(l<3){
		cout<<"No";
		return 0;
	}
	for(int i=0;i<l-2;i++){
		if((x[i]=='A'&&x[i+1]=='B'&&x[i+2]=='C')||(x[i]=='A'&&x[i+1]=='C'&&x[i+2]=='B')||(x[i]=='B'&&x[i+1]=='A'&&x[i+2]=='C')||(x[i]=='B'&&x[i+1]=='C'&&x[i+2]=='A')||(x[i]=='C'&&x[i+1]=='B'&&x[i+2]=='A')||(x[i]=='C'&&x[i+1]=='A'&&x[i+2]=='B')){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}