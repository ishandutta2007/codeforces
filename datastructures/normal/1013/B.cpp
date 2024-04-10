#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,x,a[100005],book[100005];
signed main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		book[a[i]]++;
		if (book[a[i]]>1){
			cout<<0<<endl;
			return 0;
		}
	}
	for (int i=1;i<=n;i++){
		book[a[i]]--;
		book[a[i]&x]++;
		if (book[a[i]&x]>1){
			cout<<1<<endl;
			return 0;
		}
		book[a[i]&x]--;
		book[a[i]]++;
	}
	memset(book,0,sizeof(book));
	for (int i=1;i<=n;i++){
		book[a[i]&x]++;
		if (book[a[i]&x]>1){
			cout<<2<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}