#include<algorithm>
#include<cstdio>
#include<functional>
#define Memory_of_winter std /*==std*/
using namespace Memory_of_winter;
struct B{
	int num,no;
	bool operator <(const B& $1)const{
		if(num!=$1.num)
		return num<$1.num;
		return no>$1.no;
	}
}b[200005];
int a[200005],n,val[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i].num),b[i].no=i;
	stable_sort(b+1,b+n+1);
	stable_sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i)
	val[b[i].no] = a[i];
	for(int i=1;i<=n;++i) printf("%d ",val[i]);
	return 0;
}