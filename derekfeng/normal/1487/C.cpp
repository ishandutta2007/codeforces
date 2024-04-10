#include<bits/stdc++.h>
using namespace std;
int T,n;
int w[103][103];
int main(){
	cin>>T;
	while(T--){
		memset(w,0,sizeof(w));
		cin>>n;
		if(n%2==0){
			for(int i=1;i<=n;i+=2){
				int a=i,b=i+1;
				w[a][b]=2;
				for(int j=a-2;j>0;j-=2)w[a][j]=1;
				for(int j=a+3;j<=n;j+=2)w[a][j]=1;
				for(int j=b-2;j>0;j-=2)w[b][j]=1;
				for(int j=b+1;j<=n;j+=2)w[b][j]=1;
			}
		}else{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=(n-1)/2;j++)
					w[i][(i+j-1)%n+1]=1;
		}
		for(int a=1;a<=n;a++)for(int b=a+1;b<=n;b++){
			if(w[a][b]==2)cout<<0<<" ";
			if(w[a][b]==1)cout<<1<<" ";
			if(w[a][b]==0)cout<<-1<<" ";
		}
		puts("");
	}
}