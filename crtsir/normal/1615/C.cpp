#include<bits/stdc++.h>
using namespace std;
int T=1,n;
string s,t;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s>>t;
		int cnt[2][2];memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
			cnt[0][s[i]-'0']++;
			cnt[1][t[i]-'0']++;
		}
		int ans=19260817,d=0;
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
				d++;
		if(d%2==0&&cnt[1][1]==cnt[0][1])ans=min(ans,d);
		for(int i=0;i<n;i++)s[i]='1'-s[i]+'0';
		d=0;
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])++d;
		if(d%2==1&&cnt[1][1]==n-cnt[0][1]+1)ans=min(ans,d);
		if(ans==19260817)
			cout<<"-1\n";
		else
			printf("%d\n",ans);
	}
}