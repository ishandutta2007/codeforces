#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=110;
int t,n,k,h[MAXN];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		memset(h,0,sizeof h);
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		int rest=k,flag=0,pos;
		while(rest){
			pos=1;
			while(pos<=n && h[pos]>=h[pos+1])pos++;
			if(pos==n+1){
				flag=1;
				break;
			}
			h[pos]++;
			rest--;
		}
		if(flag){
			printf("-1\n");
		}else{
			printf("%d\n",pos);
		}
	}
	return 0;
}