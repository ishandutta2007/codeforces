/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100000,M=100000;
int n,m,s;
set<pair<int,int> > p;
vector<int> v1[N+1],v2[M+1],v3[N+1],v4[M+1];
bool cmp(int x,int y){return x>y;}
int main(){
	cin>>n>>m>>s;
	while(s--){
		int x,y;
		cin>>x>>y;
		p.insert(mp(x,y));
		v1[x].pb(y);v2[y].pb(x);
	}
	for(int i=1;i<=n;i++)sort(v1[i].begin(),v1[i].end()),v3[i]=v1[i],reverse(v3[i].begin(),v3[i].end());
	for(int i=1;i<=m;i++)sort(v2[i].begin(),v2[i].end()),v4[i]=v2[i],reverse(v4[i].begin(),v4[i].end());
	int xa=1,ya=1,xb=n,yb=m;
	while(true){
		vector<int>::iterator fd=lower_bound(v1[xa].begin(),v1[xa].end(),ya);
		int fdd;
		if(fd==v1[xa].end()||*fd>yb)fdd=yb+1;else fdd=*fd;
		for(int j=fdd;j<=yb;j++)for(int i=xa;i<=xb;i++)
			if(p.find(mp(i,j))==p.end())return puts("No"),0;else p.erase(mp(i,j));
		xa++;yb=fdd-1;
//		cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<"\n";
		
		fd=lower_bound(v2[yb].begin(),v2[yb].end(),xa);
		if(fd==v2[yb].end()||*fd>xb)fdd=xb+1;else fdd=*fd;
		for(int i=fdd;i<=xb;i++)for(int j=ya;j<=yb;j++)
			if(p.find(mp(i,j))==p.end())return puts("No"),0;else p.erase(mp(i,j));
		yb--;xb=fdd-1;
//		cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<"\n";
		
		fd=lower_bound(v3[xb].begin(),v3[xb].end(),yb,cmp);
		if(fd==v3[xb].end()||*fd<ya)fdd=ya-1;else fdd=*fd;
		for(int j=ya;j<=fdd;j++)for(int i=xa;i<=xb;i++)
			if(p.find(mp(i,j))==p.end())return puts("No"),0;else p.erase(mp(i,j));
		xb--;ya=fdd+1;
//		cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<"\n";
		
		fd=lower_bound(v4[ya].begin(),v4[ya].end(),xb,cmp);
		if(fd==v4[ya].end()||*fd<xa)fdd=xa-1;else fdd=*fd;
		for(int i=xa;i<=fdd;i++)for(int j=ya;j<=yb;j++)
			if(p.find(mp(i,j))==p.end())return puts("No"),0;else p.erase(mp(i,j));
		ya++;xa=fdd+1;
//		cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<"\n";
		
		if(xa>xb||ya>yb)return puts("Yes"),0;
	}
}
/*1
6 5 21
1 4
1 5
2 1
2 4
2 5
3 1
3 4
3 5
4 1
4 4
4 5
5 1
5 2 
5 3 
5 4 
5 5
6 1 
6 2 
6 3 
6 4 
6 5
*/