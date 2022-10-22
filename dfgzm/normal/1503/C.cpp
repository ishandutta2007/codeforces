#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
struct city{
	int a,c;
}b[maxn];
bool cmp(city a,city b){
	return a.a<b.a;
}
int i,j,k,n,m,T;
int main(){
	cin>>n;
	long long Min,ans=0;
	for(i=1;i<=n;i++)b[i]={read(),read()},ans+=b[i].c;
	sort(b+1,b+1+n,cmp);Min=b[1].a+b[1].c;
	for(i=1;i<=n;i++){
		ans+=max(0ll,b[i].a-Min);
		Min=max(Min,(ll)b[i].a+b[i].c);
	}cout<<ans<<endl;
}