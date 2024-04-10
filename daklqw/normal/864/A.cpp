#include <iostream>
#include <cstdio>
using namespace std;
int t,cnt[110],n,tot,x;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>t,++cnt[t];
	for(int i=1;i<=100;++i)
		if(cnt[i]){
			++tot;
			if(x==0)x=cnt[i];
			else if(x!=cnt[i])tot=233;
		}
	if(tot==2){
		puts("YES");
		for(int i=1;i<=100;++i)
			if(cnt[i]==x)cout<<i<<" ";
		cout<<endl;
	}else puts("NO");
	return 0;
}