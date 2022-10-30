
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
char s[maxn];
int n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s);
	int sum0=0,cnt1=0;
	for (int i=0;i<n;){
		for (;i<n&&s[i]=='*';i++);
		int j=i;
		for (;j<n&&s[j]=='.';j++);
		int temp = j-i;
		if (temp&1){
			cnt1++;
			sum0+=temp-1;
		}else{
			sum0+=temp;
		}
//		cout<<temp<<endl;
		i=j+1;
	}
	int c = min(a,b);
	int ans;
//	cout<<sum0<<" "<<cnt1<<endl;
	if (c*2>=sum0){
		ans = sum0;
		a-=sum0/2;
		b-=sum0/2;
		ans+=min(cnt1,a+b);
	}else{
		ans = c*2;
		a-=c;
		b-=c;
		cnt1+=(sum0-2*c)/2;
		ans+=min(cnt1,a+b);
	}
	cout<<ans<<endl;
	return 0;
}