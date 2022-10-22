#include<bits/stdc++.h>
#define pc putchar
#define pb push_back
#define mp make_pair
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
using namespace std;
template<class T>
void read(T&x){
	x=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())f|=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<class T,class ...ARK>
void read(T&x,ARK&...ark){
	read(x);read(ark...);
}
template<class T>
void write(T x){
	if(x<0)pc('-'),x=-x;
	if(x>=10)write(x/10);
	pc(x%10+'0');
}
const int N=1e6+10;
int t,n;
int pr[N],tot;
bool npr[N];
void init(){
	for(int i=2;i<N;i++){
		if(!npr[i])pr[++tot]=i;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
}
signed main(){
	init();
	read(t);
	while(t--){
		read(n);
		long long res=*lower_bound(pr+1,pr+tot+1,n+1);
		res*=*lower_bound(pr+1,pr+1+tot,res+n);
		write(res);pc('\n');
	}
}