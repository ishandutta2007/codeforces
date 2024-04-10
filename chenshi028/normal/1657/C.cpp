#include<cstdio>
using namespace std;
const int o=5e5+10;
int T,n,ans,p,flg;char s[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d %d\n",ans,n-p+1),ans=flg=0)
		for(scanf("%d%s",&n,s+1),p=1;p<n&&!flg;)
			if(s[p]=='(') p+=2,++ans;
			else if(s[p+1]==')') p+=2,++ans;
			else for(int i=p+2;i<=n+1;++i)
				if(i>n) flg=1;else if(s[i]==')'){p=i+1;++ans;break;}
	return 0;
}