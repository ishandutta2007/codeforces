#include<cstdio>
#include<set>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=2e5+10;
int n,m,q,ans;set<int> e[o];
inline bool con(int x){if(e[x].empty()) return true;return *e[x].rbegin()<x;}
int main(){
	read(n);read(m);
	for(int i,j;m--;) read(i),read(j),e[i].insert(j),e[j].insert(i);
	for(int i=1;i<=n;++i) ans+=con(i);
	read(q);
	for(int i,j,k;q--;){
		read(i);
		if(i==1) read(j),read(k),ans-=con(j),ans-=con(k),e[j].insert(k),e[k].insert(j),ans+=con(j),ans+=con(k);
		else if(i==2) read(j),read(k),ans-=con(j),ans-=con(k),e[j].erase(k),e[k].erase(j),ans+=con(j),ans+=con(k);
		else printf("%d\n",ans);
	}
	return 0;
}