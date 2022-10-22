#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const int inf=0x3f3f3f3f;
int n,m,k;
char a[N];
char b[N],ans[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cin>>(a+1);
		for(i=1;i<=n;i++) ans[i]=a[i];
		int tmp=1;
		for(i=2;i<=n;i++){
			for(j=1;j+i-1<=n;j++)
				b[j]=a[j+i-1];
			for(j=n-i+2;j<=n;j++)
				b[j]=a[j-(n-i+1)];
			if((n-i+1)&1) reverse(b+(n-i+2),b+n+1);
			for(j=1;j<=n;j++)
				if(b[j]!=ans[j]) break;
			if(j<=n&&b[j]<ans[j]){
				tmp=i;
				for(j=1;j<=n;j++) ans[j]=b[j];
			}	
		}
		for(i=1;i<=n;i++) cout<<ans[i];
		cout<<endl<<tmp<<endl;
	}
	return 0;
}