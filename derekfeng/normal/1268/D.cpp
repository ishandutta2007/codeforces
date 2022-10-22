#include<bits/stdc++.h>
using namespace std;
int n,s[2004],d[2004];
bool e[2004][2004];char g[2004];
bool check(){
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++)s[d[i]]++;
	for(int i=0,sm=0,k=0;i<n;i++){
		while(s[i]--){
			sm+=i,k++;
			if(k<n&&sm+sm==k*(k-1))return 0;
		}
	}
	return 1;
}
void rev(int x){
	for(int i=0;i<n;i++)if(i!=x){
		if(e[x][i])d[x]--,d[i]++;
		else d[x]++,d[i]--;
		swap(e[x][i],e[i][x]);
	}
}
void sol0(){
	int ans=n+1,cnt;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++)if((i>>j)&1)rev(j);
		if(check()){
			int t=__builtin_popcount(i);
			if(t<ans)ans=t,cnt=1;
			else if(t==ans)cnt++;
		}
		for(int j=0;j<n;j++)if((i>>j)&1)rev(j);
	}
	if(ans>n)puts("-1");
	else{
		for(int i=1;i<=ans;i++)cnt*=i;
		printf("%d %d",ans,cnt);
	}
}
void sol1(){
	int cnt=0;
	for(int i=0;i<n;i++)
		rev(i),cnt+=check(),rev(i);
	printf("1 %d",cnt);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",g);
		for(int j=0;j<n;j++)if(g[j]=='1')
			e[i][j]=1,d[i]++;
	}
	if(check())return puts("0 1"),0;
	if(n<=6)sol0();else sol1();
}