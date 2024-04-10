#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,sum;bool is;
string S;
int main(){
	cin>>n;
	cin>>S;
	sum=0;is=true;
	int last=0,ans=0;
	for(i=0;i<n;i++){
		if(S[i]=='(')sum++;
		else sum--;
		if(sum<0)is=false;
		if(sum==0){
			ans+=is?0:i-last+1;
			last=i+1;
			is=true;
		}//cout<<"sum="<<sum<<' '<<ans<<endl;
	}
	if(sum)puts("-1");
	else cout<<ans<<endl;
	return 0;
}