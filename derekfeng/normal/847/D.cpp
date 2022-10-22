#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,T,ans,a;
priority_queue<int>pq;
int main(){
	read(n),read(T);
	for (int i=1;i<=n;i++){
		read(a);
		while(!pq.empty() && pq.top()>=T-i)pq.pop(); 
		if (i>=T) break;
		if (a<T)pq.push(a-i);
		ans=max(ans,(int)pq.size());
	}
	write(ans);
}