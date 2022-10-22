#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll po[20];
ll q[N];
ll s[N];
ll l[N],r[N];
int len;
void dfs(ll num,int step,int cnt){
	if(step==19){
		int k=lower_bound(q+1,q+n*2+1,num)-q;
		//cout<<num<<endl;
		s[k]++;
		return;
	}
	if(cnt<3){
		for(int i=1;i<=9;i++){
			ll tmp=num+i*po[step];
			dfs(tmp,step+1,cnt+1);
		}
	}
	dfs(num,step+1,cnt);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	po[0]=1;
	for(i=1;i<20;i++) po[i]=po[i-1]*10ll;
	for(i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		q[++len]=l[i]-1;
		q[++len]=r[i];
	}
	sort(q+1,q+2*n+1);
	dfs(0,0,0);
	for(i=1;i<=2*n;i++) s[i]+=s[i-1];
	for(i=1;i<=n;i++){
		int pos1=lower_bound(q+1,q+2*n+1,l[i]-1)-q;
		int pos2=lower_bound(q+1,q+2*n+1,r[i])-q;
		cout<<s[pos2]-s[pos1]<<endl;
	}
	return 0;
}