#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 100010
inline long long absx(long long a){return a<0?-a:a;}
int n,b[MAXN];
int judge(){
	int t=b[2]-b[1],cnt=0;
	long long now=b[2]+t;
	for(int i=3;i<=n;++i,now+=t)
		if(b[i]!=now){
			if(absx(b[i]-now)>1)return 0x3f3f3f3f;
			++cnt;
		}
	return cnt;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>b[i];
	int ans=0x3f3f3f3f;
	for(int i=-1;i<=1;++i)
		for(int j=-1;j<=1;++j){
			b[1]+=i;b[2]+=j;
			ans=min(ans,judge()+(i!=0)+(j!=0));
			b[1]-=i;b[2]-=j;
		}
	if(ans==0x3f3f3f3f)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}