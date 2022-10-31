#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e5;
bool big[maxm];
int m,n;
int ch[maxm];
int l[maxm];
int pos[maxm];
int cnt=0;
bool small(int x_,int y_){
	if (big[x_]==big[y_]){
		return x_<=y_;
	}else{
		return big[x_];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		int len;
		scanf("%d",&len);
		l[i]=len;
		pos[i] =cnt;
		for (int j=0;j<len;j++){
			scanf("%d",ch+cnt+j);
		}
		cnt+=len;
	}
	pos[n]=cnt;
	while (true){
		bool flag = false;
		for (int i=0;i<n-1;i++){
		int p1=pos[i];
		int p2 = pos[i+1];
		int l1=l[i];
		int l2 = l[i+1];
		int mm = min(l1,l2);
		int del =0;
		while (del<mm&&ch[p1+del]==ch[p2+del]){
			del++;
		}
//		cout<<i<<" "<<del<<endl;
		if (del==mm&&del==l1)continue;
		if (del==mm&&del==l2){
			cout<<"No"<<endl;
			return 0;
		}
		if (small(ch[p1+del],ch[p2+del])){
			continue;
		}else{
			if (!big[ch[p1+del]])flag = true;
			big[ch[p1+del]] =true;
			if (small(ch[p1+del],ch[p2+del])){
				continue;
			}else{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	for (int i=n-1;i>0;i--){
		int p2 = pos[i];
		int p1 = pos[i-1];
		int l2 = l[i];
		int l1 = l[i-1];
		int mm = min(l1,l2);
		int del =0;
		while (del<mm&&ch[p1+del]==ch[p2+del])del++;
//		cout<<"! "<<i<<" "<<del<<endl; 
		if (del==mm&&del==l1)continue;
		if (del==mm&&del==l2){
			cout<<"No"<<endl;
			return 0;
		}
		if (small(ch[p1+del],ch[p2+del])){
			continue;
		}else{
			if (!big[ch[p1+del]])flag = true;
			big[ch[p1+del]] = true;
			if (small(ch[p1+del],ch[p2+del])){
				continue;
			}else{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	if (!flag)break;
	}
	printf("Yes\n");
	int cnt =0;
	for (int i=1;i<=m;i++){
		if (big[i])cnt++;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=m;i++){
		if(big[i])printf("%d ",i);
	}
	return 0;
}

/*
5 5
3 1 2 3
4 1 2 4 4
3 1 3 4 
3 1 2 4
3 4 4 4

*/