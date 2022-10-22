/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	int ans=0;
	for(int i=1;i<n;i++)
		if(v[i]<v[i-1]){
			int add=v[i-1]-v[i];
			v[i]=v[i-1];
			for(int i=0;i<32;i++)if((1ll*add)&1ll<<i)ans=max(ans,i+1);
		}
	printf("%d\n",ans);
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}