#include<bits/stdc++.h>
using namespace std;
string c[105],T="theseus";
int n;
bool ok[3];
int a[3],b[3];
bool inrange(int i,int j,char C){
	return i>=0&&j>=0&&i<n&&j<n&&c[i][j]==C;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		memset(ok,1,sizeof(ok));
		for(int k=0;k<3;k++)a[k]=i,b[k]=j;
		for(int k=0;k<7;k++){
			for(int l=0;l<3;l++)
				ok[l]&=inrange(a[l],b[l],T[k]);
			a[0]++,b[1]++;
			a[2]++,b[2]++;
		}
		for(int k=0;k<3;k++)if(ok[k])return puts("YES"),0;
	}
	puts("NO");
}