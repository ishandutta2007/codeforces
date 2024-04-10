/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,x;
int a[N+1];
void mian(){
	cin>>n>>x;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	vector<int> v;
	for(int i=1;i<=n;i++)if(a[i]!=x)v.push_back(a[i]);
	if(v.empty())return puts("0"),void();
	if(v.size()<n)return puts("1"),void();
	int sum=0;
	for(int i=0;i<=n;i++)sum+=a[i];
	if(sum==x*n)return puts("1"),void();
	puts("2");
}
int main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}