//20~n-12\
\
2\
\
\
\
\
2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[150000]/**/,b[150000]/*2*/,ord[150000]/**/,las[150000]/*
*/,now[150000]/**/,will_be_las[150000]/*
*/;
ll ans[150000];//
bitset<150000> isans;//bitsetbool
bool cmp(int i,int j){//
	if(b[i]!=b[j])return b[i]<b[j];//2
	if(a[i]!=a[j])return a[i]<a[j];//
	return i<j;//
}
int main(){
	int n/**/,i,t=0/**/,nlas/*las*/,nnow/*now*/,nwill_be_las/*
	nwill_be_las*/;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		b[i]=a[i];while((b[i]&1)==0)b[i]>>=1;//2
		ord[i]=i;//0~n-1
	}
	sort(ord,ord+n,cmp);//
	for(int l=0/**/,r=0/**/;l<n;l=r/**/){//
		while(r<n&&b[ord[r]]==b[ord[l]])r++;//
		nlas=0;//las
		ll val=a[ord[l]];//
		int at=l;//
		while(nlas||at<r){
			nnow=nwill_be_las=0;//
			while(at<r&&a[ord[at]]==val)now[nnow++]=ord[at++];
			int atlas=0,atnow=0;
			while(atlas<nlas||atnow<nnow){
				int x;
				if(atlas<nlas&&(atnow==nnow||las[atlas]<now[atnow]))x=las[atlas++];
				else x=now[atnow++];
				if(atlas==nlas&&atnow==nnow){isans.set(x);ans[x]=val;t++;break;}
				if(atlas<nlas&&(atnow==nnow||las[atlas]<now[atnow]))x=las[atlas++];
				else x=now[atnow++];
				will_be_las[nwill_be_las++]=x;
			}
			nlas=nwill_be_las;for(i=0;i<nwill_be_las;i++)las[i]=will_be_las[i];
		    val<<=1;
		}
	}
	printf("%d\n",t);
	for(i=0;i<n;i++)if(isans[i])printf("%lld ",ans[i]);
	return 0;
}
/*1
7
3 4 1 2 2 1 1
*/
/*2
5
1 1 3 1 1
*/
/*3
5
10 40 20 50 30
*/