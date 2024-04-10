#include<bits/stdc++.h>

using namespace std;

const int maxn=55;

char s[maxn];
int n;

int main(){
	cin>>n>>(s+1);
	int ans=0x3ffffff;
	for(int i=1;i<=n-3;i++){
		int j=i+1,k=i+2,l=i+3;
		int a=abs((int)'A'-(int)s[i]);a=min(a,26-a);
		int b=abs((int)'C'-(int)s[j]);b=min(b,26-b);
		int c=abs((int)'T'-(int)s[k]);c=min(c,26-c);
		int d=abs((int)'G'-(int)s[l]);d=min(d,26-d);
		ans=min(ans,a+b+c+d);
	}
	cout<<ans;
	return 0;
}