// Problem: A. Simply Strange Sort
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=2000;
int t,n;int a[N];
void f(int i){
	if(a[i]>a[i+1])swap(a[i],a[i+1]);
}
bool chk(){
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1])return false;
	return true;
}
signed main(){
	read(t);
	while(t--){
		read(n);for(int i=1;i<=n;i++)read(a[i]);
		if(chk())puts("0");else{
		for(int T=1;;T++){
			if(T&1)for(int i=1;i<n;i+=2)f(i);
			else for(int i=2;i<n;i+=2)f(i);
			if(chk()){write(T),putchar('\n');break;}
		}}
	}
	return 0;
}