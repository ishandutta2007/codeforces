#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int n,m;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,d;
		cin>>n>>m>>x>>y>>d;
		int flag=0;
		if(x-1<=d)flag++;
		if(y-1<=d)flag++;
		if(n-x<=d)flag++;
		if(m-y<=d)flag++;
		if(flag==2){
			if(x-1<=d&&m-y<=d)printf("%d\n",n+m-2);
			else if(y-1<=d&&n-x<=d)printf("%d\n",n+m-2);
			else printf("%d\n",-1);
		}
		else if(flag>2){
			printf("%d\n",-1);
		}
		else printf("%d\n",n+m-2);
	}
}