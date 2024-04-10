#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int n,ans,c01,c10;
char s[N],t[N];

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	rep(i,1,n){
		if(s[i]=='4'&&t[i]=='7') c01++;
		if(s[i]=='7'&&t[i]=='4') c10++;
	}
	cout<<max(c01,c10)<<endl;
	return 0;
}