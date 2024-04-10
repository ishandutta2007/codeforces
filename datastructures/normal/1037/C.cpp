#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000
using namespace std;
int n;
char s[1000005],t[1000005];
int a[1000005],b[1000005];
int ans;
int main(){
	cin>>n;
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (int i=1;i<=n;i++)a[i]=s[i]-'0',b[i]=t[i]-'0';
	for (int i=1;i<=n;i++){
		if (a[i]==b[i])continue;
		else{
			if (i==n||a[i]==a[i+1]||a[i+1]==b[i+1]){
				ans++;
				a[i]=b[i];
			}
			else{
				ans++;
				swap(a[i],a[i+1]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}