#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=504;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
vector<int>v[404];
vector<int>num[404];
ll ret;
int main(){
	read(n),read(q);
	for (int i=0;i<n;i++)v[i/M].push_back(i),num[i/M].push_back(i); 
	while (q--){
		int l,r,a1=0,a2=0;read(l),read(r);l--,r--;
		if (l>r) swap(l,r);
		if (l/M==r/M){
			for (int i=l%M+1;i<r%M;i++){
				if (v[l/M][i]<v[l/M][l%M]) a1++;
				if (v[l/M][i]<v[l/M][r%M]) a2++;
				if (v[l/M][i]>v[l/M][l%M]) a2++;
				if (v[l/M][i]>v[l/M][r%M]) a1++;
			}
			ret+=a2-a1;
			if (v[l/M][l%M]<v[l/M][r%M]) ret++;
			if (v[l/M][l%M]>v[l/M][r%M]) ret--;
		}else{
			for (int i=l%M+1;i<M;i++){
				if (v[l/M][i]<v[l/M][l%M]) a1++;
				if (v[l/M][i]<v[r/M][r%M]) a2++;
				if (v[l/M][i]>v[l/M][l%M]) a2++;
				if (v[l/M][i]>v[r/M][r%M]) a1++;
			}
			for (int i=l/M+1;i<r/M;i++){
				int v1=lower_bound(num[i].begin(),num[i].end(),v[l/M][l%M])-num[i].begin(),v2=lower_bound(num[i].begin(),num[i].end(),v[r/M][r%M])-num[i].begin(); 
				a1+=v1+M-v2;
				a2+=v2+M-v1;
			}
			for (int i=0;i<r%M;i++){
				if (v[r/M][i]<v[l/M][l%M]) a1++;
				if (v[r/M][i]<v[r/M][r%M]) a2++;
				if (v[r/M][i]>v[l/M][l%M]) a2++;
				if (v[r/M][i]>v[r/M][r%M]) a1++;
			}
			ret+=a2-a1;
			if (v[l/M][l%M]<v[r/M][r%M]) ret++;
			if (v[l/M][l%M]>v[r/M][r%M]) ret--;
		}
		write(ret),puts("");
		int l1=lower_bound(num[l/M].begin(),num[l/M].end(),v[l/M][l%M])-num[l/M].begin(),l2=lower_bound(num[r/M].begin(),num[r/M].end(),v[r/M][r%M])-num[r/M].begin();
		swap(num[l/M][l1],num[r/M][l2]);
		sort(num[l/M].begin(),num[l/M].end()),sort(num[r/M].begin(),num[r/M].end());
		swap(v[l/M][l%M],v[r/M][r%M]);
	}
}