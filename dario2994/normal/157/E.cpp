#include <iostream>
#include <cstring>
#define mod 1000000007
using namespace std;

int din[100][25*100+1];

void preCalcola(){
	int n=100;
	int v=25*100;
	for(int i=0;i<=v;i++){
		if(i<26)din[0][i]=1;
		else din[0][i]=0;
	}
	for(int i=0;i<n;i++)din[i][0]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=v;j++){//din[i][j]
			din[i][j]=(din[i-1][j]+din[i][j-1])%mod;
			if(j>=26)din[i][j]=(mod+din[i][j]-din[i-1][j-26])%mod;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	preCalcola();
	int t;
	cin >> t;
	char s[101];
	for(int i=0;i<t;i++){
		cin >> s;
		int n=strlen(s);
		int v=0;
		for(int i=0;i<n;i++)v+=s[i]-'a';
		cout << (din[n-1][v]+mod-1)%mod << "\n";
	}
}