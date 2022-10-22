#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e6;
int n,a[o],v[o],t[o],asd;char s[o];
inline bool Cmp(int A,int B){return s[A]<s[B];}
inline bool cmp(int A,int B){if(v[A]^v[B]) return v[A]<v[B];return v[A^asd]<v[B^asd];}
int main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<(1<<n);++i) a[i]=i;
	sort(a,a+(1<<n),Cmp);
	for(int i=1;i<(1<<n);++i) t[a[i]]=t[a[i-1]]+(s[a[i]]!=s[a[i-1]]);
	for(asd=1;asd<(1<<n);asd<<=1){
		for(int j=0;j<(1<<n);++j) v[j]=t[j];
		sort(a,a+(1<<n),cmp);
		for(int j=1;j<(1<<n);++j) t[a[j]]=t[a[j-1]]+(cmp(a[j-1],a[j]));
	}
	for(int i=0;i<(1<<n);++i) putchar(s[a[0]^i]);
	return 0;
}