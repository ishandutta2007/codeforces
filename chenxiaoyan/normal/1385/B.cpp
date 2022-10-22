/*





D P //




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n;
bool hav[N+1];
void mian(){
	cin>>n;
	memset(hav,0,sizeof(hav));
	for(int i=1;i<=2*n;i++){
		int x;
		scanf("%d",&x);
		if(!hav[x])hav[x]=true,printf("%d ",x);
	}
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}