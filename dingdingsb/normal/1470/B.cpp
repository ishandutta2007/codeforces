#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=3e5+10;
int t,n,a[N],q;long long w;
map<int,int>mp;
int work(int x){
	int res=1;
	for(int i=2;i*i<=x;i++){
		int cnt=0;
		while(x%i==0){
			x/=i;
			cnt++;
		}
		if(cnt&1)res*=i;
	}
	if(x>1)res*=x;
	return res;
}
signed main(){
	read(t);
	while(t--){
		read(n);mp.clear();
		for(int i=1;i<=n;i++)
			read(a[i]),mp[work(a[i])]++;
		int ans1=0,ans2=0;
		for(auto X:mp){
			ans1=max(ans1,X.second);
			if(X.first==1||X.second%2==0){
				ans2+=X.second;
			}
		}
		read(q);
		while(q--){
			read(w);
			if(w==0)write(ans1);
			else write(max(ans1,ans2));
			putchar('\n');
		}
	}
	return 0;
	return 0;
	cout<<"AFOAFO";
}