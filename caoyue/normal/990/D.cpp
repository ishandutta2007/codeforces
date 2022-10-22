#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
int n,a,b;
bool s[1005][1005];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(n==1){
		if(a==1&&b==1){
			cout<<"YES"<<endl;
			cout<<"0"<<endl;
		}
		else cout<<"NO"<<endl;
		return 0;
	}
	if(n==2){
		if(a==1&&b==2){
			cout<<"YES"<<endl;
			cout<<"01"<<endl;
			cout<<"10"<<endl;
			return 0;
		}
		if(a==2&&b==1){
			cout<<"YES"<<endl;
			cout<<"00"<<endl;
			cout<<"00"<<endl;
			return 0;
		}
		cout<<"NO"<<endl;
		return 0;
	}
	if(a>1&&b>1){
		printf("NO\n");
		return 0;
	}
	else{
		bool flag=1;
		if(a==1&&b==1){
			if(n==3){
				cout<<"NO"<<endl;
				return 0;
			}
			cout<<"YES"<<endl;
			rep(i,n){
				if(i==1){
					cout<<"0";
					rep(j,n-2)cout<<"1";
					cout<<"0";
				}
				else if(i==2){
					cout<<"1";
					rep(j,n-2)cout<<"0";
					cout<<"1";
				}
				else if(i==n){
					cout<<"01";
					rep(j,n-2)cout<<'0';
				}
				else {
					cout<<"1";
					rep(j,n-1)cout<<'0';
				}
				cout<<endl;
			}
			return 0;
		}
		if(a==1)swap(a,b),flag=0;
		if(a>n)printf("NO\n");
		else{
			cout<<"YES"<<endl;
			memset(s,0,sizeof(s));
			rep(i,a-1)rep(j,n)if(i!=j)s[i][j]=s[j][i]=1;
			rep(i,n){
				rep(j,n)if(i==j)cout<<"0";else cout<<(s[i][j]^flag);
				cout<<endl;
			}
		}
	}
	return 0;
}