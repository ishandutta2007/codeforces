#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
vector<int> a,b;
int n,m,l,r,o;
bool ck(int o){
	int A=n,B=m;
	a.clear();
	b.clear();
	FORD(i,o,1){
		if (A>=i) A-=i,a.pb(i);
		else if (B>=i) B-=i,b.pb(i);
		else return 0;
	}
	return 1;
}
int main(){
	cin>>n>>m;
	l=1,r=1e5;
	while (l<r){
		int o=(l+r>>1)+1;
		if (ck(o)) l=o;
		else r=o-1;
	}
	ck(r);
	cout<<a.size()<<endl;
	for (int i=0;i<a.size();++i) printf("%d ",a[i]);
	puts("");
	cout<<b.size()<<endl;
	for (int i=0;i<b.size();++i) printf("%d ",b[i]);
	puts("");
	
	return 0;
}