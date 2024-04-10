#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int cnt[200];
int T;
char a[N],b[N],ans[N];
int main(){
	int i,j;
	cin>>T;
	while(T--){
		cin>>a;
		int len=strlen(a);
		for(i=len;i>0;i--)
			a[i]=a[i-1];
		sort(a+1,a+len+1);
		n=0;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=len;i++){
			if(!cnt[a[i]])
				b[++n]=a[i];
			cnt[a[i]]++;
		}
		int l=1,r=n;
		int leng=0;
		while(r>=l){
			ans[++leng]=b[l];
			l++;
			if(l>r) break;
			ans[++leng]=b[r];
			r--;
		}
		ans[0]=ans[n];
		for(i=1;i<n;i++){
			if(ans[i]==ans[i+1]-1||ans[i+1]==ans[i]-1)
				break;
		}
		if(i>=n){
			for(j=1;j<=n;j++)
				while(cnt[ans[j]]--) cout<<ans[j];
			cout<<endl;
			continue;
		}
		for(i=0;i<n-1;i++){
			if(ans[i]==ans[i+1]-1||ans[i+1]==ans[i]-1)
				break;
		}
		if(i>=n-1){
			for(j=0;j<n;j++)
				while(cnt[ans[j]]--) cout<<ans[j];
			cout<<endl;
			continue;
		}
		cout<<"No answer"<<endl;
	}
	return 0;
}