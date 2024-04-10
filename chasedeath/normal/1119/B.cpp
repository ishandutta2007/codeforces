#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=3e5+10,base=1e4;
int n,m;
int a[N];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int p=i;
		while(p>1&&a[p]<a[p-1])swap(a[p],a[p-1]),p--;
		int now=0,fl=1;
		for(int j=i;j>=1;j-=2){
			if(now+a[j]<=m)now+=a[j];
			else {fl=0;break;}
		}
		//cout<<i<<' '<<now<<endl;
		if(!fl)return printf("%d\n",i-1),0;
	}
	printf("%d\n",n);
}