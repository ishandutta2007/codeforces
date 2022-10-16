#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m;
char a[65][65];
inline bool ok(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='A')return 1;
	return 0;
}
inline bool check0(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]!='A')return 0;
	return 1;
}
inline bool check1(){
	int s;
	s=1;
	for (int i=1;i<=m;i++)
		if (a[1][i]!='A')s=0;
	if (s==1)return 1;
	s=1;
	for (int i=1;i<=m;i++)
		if (a[n][i]!='A')s=0;
	if (s==1)return 1;
	s=1;
	for (int i=1;i<=n;i++)
		if (a[i][1]!='A')s=0;
	if (s==1)return 1;
	s=1;
	for (int i=1;i<=n;i++)	
		if (a[i][m]!='A')s=0;
	if (s==1)return 1;
	return 0;
}
inline bool check2(){
	if (a[1][1]=='A'||a[1][m]=='A'||a[n][1]=='A'||a[n][m]=='A')return 1;
	for (int i=1;i<=n;i++){
		int s=1;
		for (int j=1;j<=m;j++)
			if (a[i][j]!='A')s=0;
		if (s==1)return 1;
	}
	for (int i=1;i<=m;i++){
		int s=1;
		for (int j=1;j<=n;j++)
			if (a[j][i]!='A')s=0;
		if (s==1)return 1;
	}
	return 0;
}
inline bool check3(){
	for (int i=1;i<=m;i++)
		if (a[1][i]=='A'||a[n][i]=='A')return 1;
	for (int i=1;i<=n;i++)
		if (a[i][1]=='A'||a[i][m]=='A')return 1;
	return 0;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)scanf("%s",a[i]+1);
		if (!ok())cout<<"MORTAL"<<endl;
		else if (check0())cout<<0<<endl;
		else if (check1())cout<<1<<endl;
		else if (check2())cout<<2<<endl;
		else if (check3())cout<<3<<endl;
		else cout<<4<<endl;
	}
	return 0;
}