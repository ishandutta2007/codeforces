#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
int father[MAX*3];
char ans[MAX*3];
char temp [MAX*3];
int n;
int maxlength = -1;
int find(int x){
	return father[x]==x?x:father[x]=find(father[x]);
}
int main(){
	for (int i=0;i<MAX*3;i++){
		father[i]=i;
	}
	cin>>n;
	for (int o=0;o<n;o++){
		int num;
		scanf("%s %d",temp,&num);
		int length = strlen(temp);
		for (int i=0;i<num;i++){
			int start ;
			scanf("%d",&start);
			int now = father[start];
			while (now<start+length){
				ans[now]=temp[now-start];
				father[now]=find(now+1);
				now=father[now]; 
			}
			maxlength = max (maxlength,start+length);
		}
	}
	for (int i=1;i<maxlength;i++){
		if (ans[i]>='a'&&ans[i]<='z'){
			cout<<ans[i];
		}else{
			cout<<'a';
		}
	}
	return 0;
}