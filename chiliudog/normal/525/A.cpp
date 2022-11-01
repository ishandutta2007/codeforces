#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fortodo(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
const int maxn=100001;
int n,num[29],ans=0;

inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int main(){
//	judge();
	scanf("%d\n",&n);
	fortodo(i,1,n-1){
		char ch=getchar();
		num[ch-'a']++;
		char ch2=getchar();
		if (num[ch2-'A']) num[ch2-'A']--;
							else ans++;
	}
	cout<<ans;
	return 0;
}