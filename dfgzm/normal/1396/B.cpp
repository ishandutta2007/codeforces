#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=110;
int i,j,k,n,m,a[maxn];
priority_queue<int>Q;
int main() {
	int T=read();
	while(T--){
		cin>>n;
		while(!Q.empty())Q.pop();
		for(i=1;i<=n;i++)Q.push(read());
		int last1=0;bool Tlose=1;
		while(!Q.empty()){
			Tlose^=1;
			int tmp=Q.top()-1;
			Q.pop();if(last1)Q.push(last1);
			last1=tmp;
		}cout<<(Tlose?"HL":"T")<<endl;
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}