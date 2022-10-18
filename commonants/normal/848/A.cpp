#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
#define V(l) ((l)*((l)-1)/2)
inline int lws(int k){
	int l=1,r=10000;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(V(mid)<=k)l=mid;else r=mid-1;
	}
	return l;
}
int main(){
	int k;
	scanf("%d",&k);
	char ch='a';
	while(k){
		int l=lws(k);
		k-=V(l);
		for(int i=0;i<l;i++)putchar(ch);
		ch++;
	}
	putchar(ch);
	putchar('\n');
	return 0;
}