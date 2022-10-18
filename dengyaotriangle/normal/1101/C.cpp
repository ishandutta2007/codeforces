#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

struct line{
	int l,r;
};

int m[maxn+maxn];
int u[maxn+maxn],ul;
line l[maxn];
int n;
int cp[maxn+maxn],cm[maxn+maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ul=0;
		for(int i=1;i<=n;i++){
			cin>>l[i].l>>l[i].r;
			u[++ul]=l[i].l;
			u[++ul]=l[i].r;
		}
		sort(u+1,u+1+ul);
		int cr=1;
		for(int i=1;i<=ul;i++){
			if(i!=1&&u[i]!=u[i-1]){
				cr++;
			}
			m[u[i]]=cr;
		}
		for(int i=1;i<=cr;i++){
			cp[i]=0;
		}
		for(int i=1;i<=n;i++){
			l[i].l=m[l[i].l];
			l[i].r=m[l[i].r];
			cp[l[i].l]++;
			cp[l[i].r]--;
		}
		int col=0;
		bool flg=1;
		for(int i=1;i<=cr;i++){
			col+=cp[i];
			if(i!=cr&&col==0){
				flg=0;
				for(int j=1;j<=n;j++){
					if(l[j].l<=i){
						cout<<1<<' ';
					}else{
						cout<<2<<' ';
					}
				}
				cout<<endl;
				break;
			}
		}
		if(flg){
			cout<<-1<<endl;
		}
	}
	return 0;
}