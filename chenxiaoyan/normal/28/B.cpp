#include<bits/stdc++.h>
using namespace std;
int a[101],fat[101];
int ance(int x){return fat[x]==x?x:fat[x]=ance(fat[x]);}
void merge(int x,int y){fat[ance(x)]=ance(y);}
int main(){
	int n,i;scanf("%d",&n);
	for(i=1;i<=n;i++)fat[i]=i;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++){
		int dis;scanf("%d",&dis);
		if(i-dis>=1)merge(i,i-dis);
		if(i+dis<=n)merge(i,i+dis);
	}
	for(i=1;i<=n;i++)if(fat[i]==i){
//		cout<<i<<":";
		int cnt[101]={0},j;
		for(j=1;j<=n;j++)if(ance(j)==i)
//			cout<<j<<" ",
			cnt[j]--,cnt[a[j]]++;
//		puts("");
		for(j=1;j<=n;j++)if(cnt[j])return !printf("NO");
	}
	printf("YES");
	return 0;
}
/*1
5
5 4 3 2 1
1 1 1 1 1
*/
/*2
7
4 3 5 1 2 7 6
4 6 6 1 6 6 1
*/
/*3
7
4 2 5 1 3 7 6
4 6 6 1 6 6 1
*/