#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=200010;
int i,j,k,n,m,T,s[maxn][6],a[maxn];
string S;
int main(){
	cin>>n>>m;
	cin>>S;
	for(i=1;i<=n;i++){
		if(i%3==1){
			s[i][0]=(S[i-1]!='a');
			s[i][1]=(S[i-1]!='a');
			s[i][2]=(S[i-1]!='b');
			s[i][3]=(S[i-1]!='b');
			s[i][4]=(S[i-1]!='c');
			s[i][5]=(S[i-1]!='c');
		}
		if(i%3==2){
			s[i][0]=(S[i-1]!='b');
			s[i][1]=(S[i-1]!='c');
			s[i][2]=(S[i-1]!='a');
			s[i][3]=(S[i-1]!='c');
			s[i][4]=(S[i-1]!='a');
			s[i][5]=(S[i-1]!='b');
		}
		if(i%3==0){
			s[i][0]=(S[i-1]!='c');
			s[i][1]=(S[i-1]!='b');
			s[i][2]=(S[i-1]!='c');
			s[i][3]=(S[i-1]!='a');
			s[i][4]=(S[i-1]!='b');
			s[i][5]=(S[i-1]!='a');
		}
		s[i][0]+=s[i-1][0];
		s[i][1]+=s[i-1][1];
		s[i][2]+=s[i-1][2];
		s[i][3]+=s[i-1][3];
		s[i][4]+=s[i-1][4];
		s[i][5]+=s[i-1][5];
	//	cout<<s[i][0]<<' '<<s[i][1]<<' '<<s[i][2]<<' '<<s[i][3]<<' '<<s[i][4]<<' '<<s[i][5]<<endl;
	}
	for(i=1;i<=m;i++){
		int l,r,ans=1e9;
		l=read();r=read();
		for(j=1;j<=6;j++)ans=min(ans,s[r][j-1]-s[l-1][j-1]);
		printf("%d\n",ans);
	}
}