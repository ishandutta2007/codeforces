#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
const int MX=1000011,md=1000000007;
char ch[MX];
int n;
int pw(int x,int y){
	y=(y+md-1)%(md-1);
	int ans=1;
	while(y){
		if(y&1)ans=(LL)ans*x%md;
		x=(LL)x*x%md;y>>=1;
	}
	return ans;
}
int main(){
	scanf("%s",ch);
	n=strlen(ch);
	int lsta=0;
	int i,j;LL ans=0LL;
	for(i=0;i<n;i=j){
		int cur=0;
		for(j=i;j<n&&ch[j]==ch[i];j++){
			cur++;
		}
		if(ch[i]=='b')ans=(ans+(LL)cur*((pw(2,lsta)+md-1)%md)%md)%md;
		else lsta=(lsta+cur)%md;
	}
	printf("%d\n",(int)ans);
	return 0;
}