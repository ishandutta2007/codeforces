#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
int n,top,p;
char s[N];

int main(){
	read(n);
	scanf("%s",s+1);
	rep(i,1,n)
		if(s[i]=='(')top++;
		else{
			top--;
			if(top<0){
				p=i;
				break;
			}
		}
	if(!p&&!top){
		puts("Yes");
		return 0;
	}
	if(!p&&top){
		puts("No");
		return 0;
	}
	top=0;
	rep(i,p+1,n)
		if(s[i]=='(')top++;
		else{
			top--;
			if(top<0){
				puts("No");
				return 0;
			}
		}
	if(top!=1){
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}