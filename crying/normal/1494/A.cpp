#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=100;
int T,n,a[MAXN];
char s[MAXN];
void Replace(int x,int y,int z){
	rep(i,1,n){
		if(s[i]=='A'){
			if(x)a[i]=-1;
			else a[i]=1;
		}else if(s[i]=='B'){
			if(y)a[i]=-1;
			else a[i]=1;
		}else{
			if(z)a[i]=-1;
			else a[i]=1;
		}
	}
}
bool Check(){
	int sum=0;
	rep(i,1,n){
		sum+=a[i];
		if(sum<0)return false;
	}
	return (sum==0);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		rep(x,0,1){
			rep(y,0,1){
				rep(z,0,1){
					//0 1
					Replace(x,y,z);
					if(Check())goto END;
				}
			}
		}
		printf("NO\n");continue;
		END:printf("YES\n");
	} 
	return 0;
}