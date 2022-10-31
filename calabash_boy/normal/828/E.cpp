#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
inline int lowbit(int x){
	return (x&-x);
}
struct BIT{
	int tree[MAXN];
	void add (int start,int delta){
		while (start<MAXN){
			tree[start]+=delta;
			start+=lowbit(start);
		}
	}
	int get (int start){
		int ans =0;
		while (start>0){
			ans+=tree[start];
			start-=lowbit(start);
		}
		return ans;
	}
}tree[11][11][4];
int q;
int mp[256];
char a[MAXN];
char tempString [20];
int main(){
	mp['A']=0;
	mp['T']=1;
	mp['G']=2;
	mp['C']=3;
	scanf("%s%d",a+1,&q);
	int length = strlen(a+1);
	for (int i=1;i<=10;i++){
		for (int j=1;j<=length;j++){
			tree[i][j%i][mp[a[j]]].add(j,1);
		}
	}
	while (q--){
		int op;
		scanf("%d",&op);
		if (op==1){
			int start;
			scanf("%d%s",&start,tempString);
			for (int i=1;i<=10;i++){
				tree[i][start%i][mp[a[start]]].add(start,-1);
				tree[i][start%i][mp[tempString[0]]].add(start,1);
			}
			a[start]=tempString[0];
		}else{
			int l,r;
			scanf("%d%d%s",&l,&r,tempString);
			int len = strlen(tempString);
			int ansSum = 0;
			for (int i=0;i<len;i++){
				ansSum+=tree[len][(l+i)%len][mp[tempString[i]]].get(r)-tree[len][(l+i)%len][mp[tempString[i]]].get(l-1);
			}
			cout<<ansSum<<endl;
		}
	} 
	return 0;
}