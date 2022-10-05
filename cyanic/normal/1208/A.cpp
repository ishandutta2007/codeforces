#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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



int main(){
	int T,a,b,n;

	cin>>T;
	while(T--){
		cin>>a>>b>>n;
		if(n==0)printf("%d\n",a);
		else if(n==1)printf("%d\n",b);
		else {
			int res=0;b^=a;
			if(n%3<=1)res^=a;
			if((n-1)%3<=1)res^=b;
			printf("%d\n",res);
		}
	}

	
	return 0;
}