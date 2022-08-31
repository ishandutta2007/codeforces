#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n,cnt=0;
	char c[200][200];
	cin>>n;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		cin>>c[i][j];
	}
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		for(int k=i+1;k<n;k++)
		if(c[i][j]=='C' && c[k][j]=='C')
		cnt++;
		
		for(int k=j+1;k<n;k++)
		if(c[i][j]=='C' && c[i][k]=='C')
		cnt++;
		
	}

	cout<<cnt;
	return 0;
}