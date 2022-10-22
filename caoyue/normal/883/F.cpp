#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
string s[405];
int a[405][45];
int b[405][45];
bool c[405];
int main(){
	int n;
	cin>>n;
	rep(i,n)cin>>s[i];
	rep(i,n){
		int x=s[i].length();
		rep(j,x){
			if(s[i][j-1]=='u'){
				a[i][j*2-1]=14;
				a[i][j*2]=14;
				continue;
			}
			a[i][j*2-1]=s[i][j-1]-'a';
			a[i][j*2]=-1;
		}
		a[i][x*2+1]=1;
		rep(jk,x*2){
			int now=1,nowp=1;
			while(a[i][now]<0)now++;
			nowp=now+1;
			while(a[i][nowp]<0)nowp++;
			bool flag=0;
			while(nowp<=x*2){
				//cout<<a[i][now]<<" "<<a[i][nowp]<<endl;
				if(a[i][now]==10&&a[i][nowp]==7){
					a[i][now]=7;
					a[i][nowp]=-1;
					flag=1;
				}
				now++;
				while(a[i][now]<0)now++;
				nowp=now+1;
				while(a[i][nowp]<0)nowp++;
			}
		}
		b[i][0]=0;
		int t=0;
		while(t<=x*2){
			t++;
			while(a[i][t]<0)t++;
			b[i][++b[i][0]]=a[i][t];
			//cout<<b[i][b[i][0]]<<" ";
		}
		//cout<<endl;
	}
	memset(c,1,sizeof(c));
	int ans=0;
	rep(i,n){
		if(!c[i])continue;
		ans++;
		for(int j=i+1;j<=n;j++){
			if(b[i][0]!=b[j][0])continue;
			bool flag=1;
			rep(k,b[i][0])if(b[i][k]!=b[j][k]){
				flag=0;
				break;
			}
			if(flag)c[j]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}