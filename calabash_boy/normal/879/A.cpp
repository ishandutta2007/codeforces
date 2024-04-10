#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
typedef long long LL;
int d[maxn],s[maxn];
int n;
int main(){
	LL ans =0;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",s+i,d+i);
	}
	LL now = s[0];
	for (int i=1;i<n;i++){
		LL temp=s[i];
		while (temp<=now)temp+=d[i];
		ans +=temp-now;
		now = temp;
	}
	cout<<now<<endl;
	return 0;
}