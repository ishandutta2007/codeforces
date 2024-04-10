/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=100000,M=100000;
int n,m;
char a[N+5],b[M+5];
int Pos[M+1],poS[M+2];
int main(){
	cin>>a+1>>b+1;
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=m;i++){
		Pos[i]=Pos[i-1]+1;
		while(Pos[i]<=n&&a[Pos[i]]!=b[i])Pos[i]++;
//		cout<<Pos[i]<<" ";
	}
//	puts("");
	poS[m+1]=n+1;
	for(int i=m;i;i--){
		poS[i]=poS[i+1]-1;
		while(poS[i]>=1&&a[poS[i]]!=b[i])poS[i]--;
//		cout<<poS[i]<<" ";
	}
//	puts("");
	pair<int,pair<int,int> > ans(0,mp(0,0));
	for(int i=0;i<=m;i++)if(poS[m-i+1]>=1){
		int fd=lower_bound(Pos+1,Pos+m+1,poS[m-i+1])-1-Pos;
		fd=min(fd,m-i);
		ans=max(ans,mp(fd+i,mp(fd,i)));
	}
	for(int i=1;i<=ans.Y.X;i++)cout<<b[i];
	for(int i=m-ans.Y.Y+1;i<=m;i++)cout<<b[i];
	if(ans.Y.X==0&&ans.Y.Y==0)puts("-");
	return 0;
}