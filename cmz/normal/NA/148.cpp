#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	scanf("%I64d",&n);
	while (n--){
		long long a,b;
		scanf("%I64d%I64d",&a,&b);
		long long ans=0;
		while (a>0){
			if (a%b==0) {
				a=a/b;
				++ans;
			}
			else {
				ans+=(a%b);
				a-=(a%b);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}