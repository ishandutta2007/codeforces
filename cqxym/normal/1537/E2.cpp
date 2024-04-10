#include<stdio.h>
#include<algorithm>
#include<time.h>
#define R register int
#define L long long
#define I inline
#define N 500001
I int Min(int a,const int b,const int c){
	a=a<b?a:b;
	return a<c?a:c;
}
char s[N];
I int GetPrime(){
	while(true){
		int x=999999999-(rand()&32767);
		bool tag=true;
		for(R i=2;i*i<=x;i++){
			if(x%i==0){
				tag=false;
				break;
			}
		}
		if(tag==true){
			return x;
		}
	}
}
int h[N],pw[N];
I int GetHash(int l,int r,int&P){
	int t=h[r]-(L)h[l-1]*pw[r-l+1]%P;
	return t<0?t+P:t;
}
I int Calc(int l1,int r1,int l2,int r2,int&P){
	if(s[l1]<s[l2]){
		return-1;
	}
	if(s[l1]>s[l2]){
		return 1;
	}
	int len=r1-l1<r2-l2?r1-l1:r2-l2,l=0,r,mid,res;
	r=len;
	while(l<=r){
		mid=l+r>>1;
		if(GetHash(l1,l1+mid,P)==GetHash(l2,l2+mid,P)){
			res=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	if(res==len){
		if(r1-l1==r2-l2){
			return 0;
		}
		if(r1-l1<r2-l2){
			return-1;
		}
		return 1;
	}
	if(s[l1+res+1]<s[l2+res+1]){
		return-1;
	}
	return 1;
}
I bool Compare(int l1,int l2,int&k,int&P){
	int cur=1,cur1=1,cur2=1;
	while(cur<=k){
		int len=Min(k-cur,l1-cur1,l2-cur2),r;
		r=Calc(cur1,cur1+len,cur2,cur2+len,P);
		if(r==-1){
			return true;
		}else if(r==1){
			return false;
		}
		len++;
		cur+=len;
		cur1+=len;
		if(cur1>l1){
			cur1=1;
		}
		cur2+=len;
		if(cur2>l2){
			cur2=1;
		}
	}
	return false;
}
int main(){
	srand(time(0));
	pw[0]=1;
	int n,cur,k,P=GetPrime();
	scanf("%d%d\n",&n,&k);
	for(R i=1;i<=n;i++){
		scanf("%c",s+i);
		h[i]=(29ll*h[i-1]+s[i]-'a')%P;
		pw[i]=29ll*pw[i-1]%P;
	}
	cur=n;
	for(R i=n-1;i!=0;i--){
		if(Compare(i,cur,k,P)==true){
			cur=i;
		}
	}
	n=1;
	for(R i=k;i!=0;i--){
		putchar(s[n]);
		n++;
		if(n>cur){
			n=1;
		}
	}
	return 0;
}