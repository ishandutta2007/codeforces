#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int n,m,a[250005];
int pos[250005][10],Pos[250005][10],len[250005],Len[250005],ans[250005],Ans[250005],fg;
int val[250005];
int num,id;
inline int ID(register int i,register int j){
	return (i-1)*m+j;
}
inline int Mod(register int i,register int j){
	if (i%j==0)return j;
	return i%j;
}
inline void Copy1(){
	for (register int i=0;i<250005;i++)
		for (register int j=0;j<10;j++)Pos[i][j]=pos[i][j];
	for (register int i=0;i<250005;i++)Len[i]=len[i],Ans[i]=ans[i];
	return;
}
inline void Copy2(){
	for (register int i=0;i<250005;i++)
		for (register int j=0;j<10;j++)pos[i][j]=Pos[i][j];
	for (register int i=0;i<250005;i++)len[i]=Len[i],ans[i]=Ans[i];
	return;
}
inline void upd(){
	fg=1;
	memset(len,0,sizeof(len));
	memset(pos,0,sizeof(pos));
	for (register int i=1;i<=m&&fg==1;i++){
		for (register int j=i;j<=n*m&&fg==1;j+=m)
			if (a[j]!=ans[i]){
				++len[(j-1)/m+1];
				if (len[(j-1)/m+1]>4){
					fg=0;
					break;
				}
				else pos[(j-1)/m+1][len[(j-1)/m+1]]=i;
			}
	}
	return;
}
inline bool chk(){
	for (register int i=1;i<=n;i++)
		if (len[i]>2)return 0;
	return 1;
}
inline void Out(){
	cout<<"Yes"<<endl;
	for (register int i=1;i<=m;i++)printf("%d ",ans[i]);
	cout<<endl;
	return;
}
int main(){
	cin>>n>>m;
	for (register int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	for (register int i=1;i<=m;i++)ans[i]=a[i];
	upd();
	if (fg==0){
		cout<<"No"<<endl;
		return 0;
	}
	if (chk()){
		Out();
		return 0;
	}
	for (register int i=1;i<=n;i++)
		if (len[i]>num)num=len[i],id=i;
	if (num==3){
		Copy1();
		for (register int i=1;i<=3;i++){
			ans[pos[id][i]]=a[ID(id,pos[id][i])];
			upd();
			if (chk()){
				Out();
				return 0;
			} 
			int Num=0,Id=0;
			for (register int j=1;j<=n;j++)
				if (len[j]>Num)Num=len[j],Id=j;
			if (Num==3){
				for (register int j=1;j<=3;j++){
					int last=ans[pos[Id][j]];
					ans[pos[Id][j]]=a[ID(Id,pos[Id][j])];
					int nownum=0;
					memset(val,0,sizeof(val));
					for (register int k=1;k<=m;k++){
						for (register int kk=k;kk<=n*m;kk+=m)
							if (a[kk]!=ans[k]){
								val[(kk-1)/m+1]++;
								nownum=max(nownum,val[(kk-1)/m+1]);
							}
					}
					if (nownum<=2){
						Out();
						return 0;
					}
					ans[pos[Id][j]]=last;
				}
			}
			Copy2();
		}
	}
	if (num==4){
		Copy1();
		for (register int i=1;i<=4;i++){
			for (register int j=1;j<i;j++){
				ans[pos[id][i]]=a[ID(id,pos[id][i])],ans[pos[id][j]]=a[ID(id,pos[id][j])];
				upd();
				if (chk()){
					Out();
					return 0;
				}
				Copy2();
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}