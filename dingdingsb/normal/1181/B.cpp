#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int x,num[2][maxn];
char n[maxn];
void print(int k){
	bool flag=false;
	for(int i=maxn-1;i>=1;i--){
		if(num[k][i])flag=true;
		if(flag)putchar(num[k][i]+'0');
	}
}
signed main(){
	//freopen("split.in","r",stdin);
	//freopen("split.out","w",stdout);
	cin>>x>>n+1;
	int s=x/2,t=x-x/2;
	while(n[s+1]=='0'&&n[t+1]=='0')s--,t++;
	if(n[s+1]!='0'){
		for(int i=s,j=1;i>=1;i--,j++)
			num[0][j]+=n[i]-'0';
		for(int i=x,j=1;i>s;i--,j++)
			num[0][j]+=n[i]-'0';
		for(int i=1;i<maxn-1;i++)
			num[0][i+1]+=num[0][i]/10,num[0][i]%=10;
	}if(n[t+1]!='0'){
		for(int i=t,j=1;i>=1;i--,j++)
			num[1][j]+=n[i]-'0';
		for(int i=x,j=1;i>t;i--,j++)
			num[1][j]+=n[i]-'0';
		for(int i=1;i<maxn-1;i++)
			num[1][i+1]+=num[1][i]/10,num[1][i]%=10;
	}
	if(n[s+1]=='0')print(1);
	else if(n[t+1]=='0')print(0);
	else{
		int nnn=0;
		for(int i=maxn-1;i>=1;i--)
			if(num[0][i]!=num[1][i]){
				if(num[0][i]<num[1][i]){break;}
				if(num[0][i]>num[1][i]){nnn=1;break;}
			}
		print(nnn);
	}
}