#include <iostream>
#include <cstdio>
using namespace std;
int n,a[105];
int tot,len[105],k[105][105];
int l[105],r[105],_a[105];
void work(int id){
	int p=0;
	for (int i=1;i<=len[id];i++){
		l[i]=p+1,r[i]=p+k[id][i];
		p=r[i];
	}
	for (int i=1,j=len[id];i<j;i++,j--)swap(l[i],l[j]),swap(r[i],r[j]);
	for (int i=1;i<=n;i++)_a[i]=a[i];
	int qwq=0;
	for (int i=1;i<=len[id];i++)
		for (int j=l[i];j<=r[i];j++)a[++qwq]=_a[j];
	return;
}
int main(){
	cin>>n;
	int pos1=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1)pos1=i;
	}
	if (pos1!=1){
		++tot;
		len[tot]=2;
		k[tot][1]=pos1-1,k[tot][2]=n-pos1+1;
		work(tot);
	}
	for (int i=2;i<=n;i++){
		int pos=0;
		for (int j=1;j<=n;j++)
			if (a[j]==i)pos=j;
		if (a[1]==1){
			if (pos==i)continue;
			++tot;
			for (int j=1;j<i;j++)k[tot][++len[tot]]=1;
			k[tot][++len[tot]]=pos-(i-1);
			if (pos<n)k[tot][++len[tot]]=n-pos;
			work(tot);
		}
		else{
			if (pos==n-i+1)continue;
			++tot;
			if (pos>1)k[tot][++len[tot]]=pos-1;
			k[tot][++len[tot]]=(n-i+1)-pos+1;
			for (int j=1;j<i;j++)k[tot][++len[tot]]=1;
			work(tot);
		}
	}
	if (a[1]!=1){
		++tot;
		for (int i=1;i<=n;i++)k[tot][++len[tot]]=1;
		work(tot);
	}
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++){
		cout<<len[i]<<' ';
		for (int j=1;j<=len[i];j++)cout<<k[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}