//  228

#include<bits/stdc++.h>
using namespace std;
string s;
int sum,n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=="ABSINTH"||s=="BEER"||s=="BRANDY"||s=="CHAMPAGNE"||s=="GIN"||s=="RUM"||s=="SAKE"||s=="TEQUILA"||s=="VODKA"||s=="WHISKEY"||s=="WINE")sum++;
		if(s=="1"||s=="2"||s=="3"||s=="4"||s=="0"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="10"||s=="11"||s=="12"||s=="13"||s=="14"||s=="15"||s=="16"||s=="17")sum++;
	}
	cout<<sum<<endl;
	return 0;
}