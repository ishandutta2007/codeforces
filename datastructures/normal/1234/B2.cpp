#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n,k,a[200005],q[500005],head=1,tail=0;
map <int,int>book;
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		if (book[a[i]]==1)continue;
		book[a[i]]=1;
		q[++tail]=a[i];
		if (tail-head+1>k)book[q[head]]=0,head++;
	}
	cout<<tail-head+1<<endl;
	for (int i=tail;i>=head;i--)printf("%d ",q[i]);
	return 0;
}