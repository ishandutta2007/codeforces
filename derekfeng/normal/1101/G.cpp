#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200004],S,ans,b[30];
void upd(int x){
	for(int i=30;~i;i--)if((1<<i)&x){
		if(!b[i]){
			b[i]=x;
			ans++;
			break;
		}
		x^=b[i];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),S^=a[i];
	if(S==0)return puts("-1"),0;
	for(int i=1;i<=n;i++)upd(a[i]);
	printf("%d",ans);
}