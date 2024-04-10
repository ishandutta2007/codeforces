#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
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

const int N=1000005;
int x[32],a[N],n;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		for(int k=30;k>=0;k--)
			if(a[i]>>k&1){
				if(!x[k]) x[k]=i;
				else x[k]=-1;
			}
	}
	int k=30,fir=0;
	for(;k>=0;k--)
		if(x[k]>0){
			fir=x[k];
			break;
		}
	if(fir) swap(a[1],a[fir]);
	rep(i,1,n) printf("%d ",a[i]);
	puts("");
	return 0;
}