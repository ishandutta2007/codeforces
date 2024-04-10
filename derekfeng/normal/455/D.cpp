#include <bits/stdc++.h>
using namespace std;
const int M=320;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
deque<int>a[325]; 
int cnt[325][100004];
int l,r,k,ans,oper;
void go(int &x){
	x=((x+ans-1)%n)+1;
}
int main(){
	read(n);
	for (int i=0;i<n;i++){
		int x;read(x);
		a[i/M].push_back(x);
		cnt[i/M][x]++;
	}
	read(q);
	while(q--){
		read(oper),read(l),read(r);
		go(l),go(r);l--,r--;
		if (l>r) swap(l,r);
		if (oper==2){
			read(k),go(k);
			ans=0; 
			if (l/M==r/M){
				for (int i=l%M;i<=r%M;i++)if(a[l/M][i]==k)ans++;
				write(ans),puts("");continue;
			}
			for (int i=l%M;i<a[l/M].size();i++)if(a[l/M][i]==k)ans++;
			for (int i=l/M+1;i<r/M;i++) ans+=cnt[i][k];
			for (int i=0;i<=r%M;i++)if(a[r/M][i]==k)ans++;
			write(ans),puts("");continue;
		}
		if (l/M==r/M){
			int x=a[l/M][r%M];
			a[r/M].erase(a[r/M].begin()+r%M);
			a[r/M].insert(a[r/M].begin()+l%M,x);
			continue;
		}
		int x=a[r/M][r%M];
		a[r/M].erase(a[r/M].begin()+r%M),cnt[r/M][x]--;
		for (int i=l/M+1;i<=r/M;i++) a[i].push_front(a[i-1].back()),cnt[i][a[i-1].back()]++,cnt[i-1][a[i-1].back()]--,a[i-1].pop_back();
		a[l/M].insert(a[l/M].begin()+l%M,x),cnt[l/M][x]++;
	}
}