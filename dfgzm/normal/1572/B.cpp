#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,a[200010],s[200010];
vector<int>ans;
int main(){
	cin>>T;
	while(T--){
		ans.clear();
		cin>>n;
		bool b=false;
		for(i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
		for(i=1;i<=n;i++)if(a[i]==0 && (s[i-1]%2==0 || (a[i-1]==1 && a[i+1]==1)) && s[n]%2==0){
			puts("YES");
			if(s[i-1]%2)ans.push_back(i-1),a[i-1]=0,a[i+1]=0;
			for(j=i-1;j>=1;j--)
				if(a[j]!=0){
					if(a[j-1]!=0)ans.push_back(j-1),a[j-1]=0,a[j]=0;
					else if(a[j-2]!=0)ans.push_back(j-2),a[j-2]=0,a[j]=0;
					else ans.push_back(j-2),ans.push_back(j-1),a[j]=0,a[j-2]=1;
				}
			for(j=i+1;j<=n;j++)
				if(a[j]!=0){
					if(a[j+1]!=0)ans.push_back(j-1),a[j+1]=0,a[j]=0;
					else if(a[j+2]!=0)ans.push_back(j),a[j+2]=0,a[j]=0;
					else ans.push_back(j),ans.push_back(j-1),a[j]=0,a[j+2]=1;
				}
			cout<<ans.size()<<endl;
			for(j=0;j<ans.size();j++)printf("%d ",ans[j]);cout<<endl;
			break;
		}else if(a[i]==0 && a[i-1]==0 && a[i-2]==1)a[i]=1,a[i-1]=1,ans.push_back(i-2);
		if(i>n)puts("NO");
	}
}