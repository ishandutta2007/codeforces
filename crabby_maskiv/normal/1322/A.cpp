#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int n,m;
char a[N];
int main(){
	int i,j;
	scanf("%d",&n);
	scanf("%s",a+1);
	int cnt=0,ans=0;
	for(i=1;i<=n;i++){
		if(a[i]=='('){
			cnt++;
			if(cnt<=0) ans++;
		}
		else{
			cnt--;
			if(cnt<0) ans++;
		}
	}
	if(cnt!=0) cout<<-1;
	else cout<<ans;
	return 0;
}