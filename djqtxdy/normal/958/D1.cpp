/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=200005;
int n,pos;
char c[maxn];
map<double,int>m;
double cor[maxn];

int read(string s){
	int res=0;
	while(pos<s.size()&&isdigit(s[pos]))res=res*10+s[pos]-'0',pos++;
	return res;
} 

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",c);
		string cur=c;
		pos=1;
		int a=read(cur);pos++;
		int b=read(cur);pos+=2;
		int c=read(cur);
		cor[i]=((double)a+(double)b)/(double)c;
		m[cor[i]]++;
	}
	rep(i,n)printf("%d ",m[cor[i]]);
	return 0;
}

/*
Input:
-----------------
Output:
*/