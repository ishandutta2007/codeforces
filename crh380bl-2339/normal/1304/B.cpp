#include<bits/stdc++.h>
using namespace std;
string s[105],t;
int match[105],id[105];
int main(){
	int n,m,i,j,ans=0,cnt=0;
	bool flg=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		cin>>s[i];
		t="";
		for(j=m-1;j>=0;--j)t=t+s[i][j];
		for(j=1;j<=i;++j){
			if(s[j]==t&&(match[j]==0||match[j]==j)){
				match[i]=j;
				match[j]=i;
			}
		}
	}
	//for(i=1;i<=n;++i)printf("%d ",match[i]);
	for(i=1;i<=n;++i)if(match[i]&&match[i]!=i)++ans;
	for(i=1;i<=n;++i)if(match[i]==i){
		++ans;
		flg=1;
		break;
	}
	printf("%d\n",ans*m);
	for(i=1;i<=n;++i){
		if(match[i]&&match[i]>i){
			if((cnt+1)*2<=ans){
				cout<<s[i];
				id[++cnt]=i;
			}
		}
	}
	if(flg)for(i=1;i<=n;++i)if(match[i]==i){
		cout<<s[i];
		break;
	}
	for(i=cnt;i>=1;--i)cout<<s[match[id[i]]];
	return 0;
}