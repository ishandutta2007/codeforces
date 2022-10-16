#include <iostream>
#include <cstdio>
using namespace std;
int n,ans;
char a[200005];
int main(){
//	freopen("1108D.in","r",stdin);
//	freopen("1108D.out","w",stdout);
	cin>>n;
	scanf("%s",a+1);
	for (int i=2;i<=n;i++){
		if (a[i]==a[i-1]){
			ans++;
			if (a[i-1]=='R'){
				if (a[i+1]=='R')a[i]='G';
				else if (a[i+1]=='G')a[i]='B';
				else a[i]='G';
			}
			if (a[i-1]=='G'){
				if (a[i+1]=='G')a[i]='B';
				else if (a[i+1]=='B')a[i]='R';
				else a[i]='B';
			}
			if (a[i-1]=='B'){
				if (a[i+1]=='B')a[i]='G';
				else if (a[i+1]=='R')a[i]='G';
				else a[i]='R';
			}
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)printf("%c",a[i]);
	cout<<endl;
	return 0;
}