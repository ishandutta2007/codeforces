/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int n,m;
char a[N+5];
void mian(){
	scanf("%d%d%s",&n,&m,a+1);
	int sum=0,all=0;
	for(int i=1;i<=m;i++){
		bool zero=false,one=false,que=false;
		for(int j=i;j<=n;j+=m)
			zero|=a[j]=='0',
			one|=a[j]=='1',
			que|=a[j]=='?';
		if(zero&&one)return puts("NO"),void();
		if(!zero&&!one)all++;
		else if(one)sum++;
	}
	if(sum<=m/2&&m/2<=sum+all)return puts("YES"),void();
	puts("NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}