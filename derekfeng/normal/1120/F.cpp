#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,d;
ll ans,res;
char buf[4];
int lst,t[100004],w[100004];
int main(){
	scanf("%d%d%d",&n,&c,&d);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&t[i],buf);
		w[i]=(*buf=='P');
	}
	scanf("%d",&lst);
	ans=(ll)n*d;res=0;
	for(int i=n;i;i--){
		if(i==n)res=c*(lst-t[i]);
		else{
			if(w[i]!=w[i+1]){
				lst=t[i+1];
				res+=(lst-t[i])*c;
			}else{
				res+=(t[i+1]-t[i])*c;
				res+=min((lst-t[i+1])*c,d);
			}
		}
		ans=min(ans,res+(ll)(i-1)*d);
	}
	printf("%I64d",ans);
}