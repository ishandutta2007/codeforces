#include<stdio.h>   
#include<string.h>   
#include<algorithm>   
using namespace std;  
  
typedef __int64 lld;
const int maxn=200005;  
  
//   
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];  
int cmp(int *r,int a,int b,int l)  
{return r[a]==r[b]&&r[a+l]==r[b+l];}  
  
void da(const int *r,int *sa,int n,int m){  
    int i,j,p,*x=wa,*y=wb,*t;   
    for(i=0;i<m;i++) Ws[i]=0;   
    for(i=0;i<n;i++) Ws[x[i]=r[i]]++;   
    for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
    for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;   
    for(j=1,p=1;p<n;j*=2,m=p){   
        for(p=0,i=n-j;i<n;i++) y[p++]=i;   
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;   
        for(i=0;i<n;i++) wv[i]=x[y[i]]; //x[]->   
        for(i=0;i<m;i++) Ws[i]=0;   
        for(i=0;i<n;i++) Ws[wv[i]]++;   
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
        for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];   
        //y[i]->in-10   
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)   
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;   
    }   
    return;   
}  
int sa[maxn],Rank[maxn],height[maxn];  
//height   
//sa[1,n][0,n-1],sa[0]   
//Rank[0,n-1][1,n]   
//height[1,n]   
//height[i]sa[i]sa[i-1] ii-1   
void calheight(const int *r,int *sa,int n){  
    int i,j,k=0;  
    for(i=1;i<=n;i++) Rank[sa[i]]=i;  
    for(i=0;i<n;height[Rank[i++]]=k)  
        for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);  
    return;  
}  
/* 
da(r,sa,n+1,128); 
n+1[0,n]; 
calheight(r,sa,n); 
[1,n]n 
*/  
  
int LOG[maxn];  
int dp[20][maxn];  
  
int Min(int a,int b){  
    if(a<b)return a;  
    return b;  
}  
  
void RMQ(int m){  
    int i,j;  
    LOG[0]=-1;  
    for(i=1;i<=m;i++)  
        LOG[i]=LOG[i>>1]+1;  
    for(i=1;i<=m;i++)  
        dp[0][i]=height[i];  
    for(j=1;j<=LOG[m];j++){  
        int limit=m+1-(1<<j);  
        for(i=1;i<=limit;i++){  
            int x=i+(1<<j>>1);  
            dp[j][i]=Min(dp[j-1][x],dp[j-1][i]);  
        }  
    }  
}  
  
int lcp(int l,int r,int len){
	//l,r,b[l],b[r],len
    if(l==r) return len;
	l=Rank[l];r=Rank[r];  
    if(l>r){  
        int tmp=l;l=r;r=tmp;  
    }  
    l++;//height[i]ii-1lcp   
    int m=LOG[r-l+1];  
    return Min(dp[m][l],dp[m][r-(1<<m)+1]);  
}  

char b[maxn];
int a[maxn];
int len[maxn];

int Gao(int li,int ri,int len){
	if(height[li]<len || li>ri)
		return li-1;
	int best=li;
	int l=li,r=ri;//Rank[l,r];
	while(l<=r){
		int mid=(l+r)>>1;
		if(lcp(sa[li],sa[mid],len)>=len){//sa[li]Rankli
			l=mid+1;
			best=mid;
		}else{
			r=mid-1;
		}
	}
	return best;
}

int main(){
	int cas=1;
	int n,m;
	int i,j;
	while(scanf("%s",b)!=EOF ){
		n=strlen(b);
		scanf("%d",&m);
		for(i=0;i<n;i++)
			a[i]=b[i]-'a'+1;
		a[n]=0;
		da(a,sa,n+1,30);
		calheight(a,sa,n);
		RMQ(n);
		if(m>(lld)n*(n+1)/2){
			puts("No such line.");
			continue;
		}
		/*
		for(i=1;i<=n;i++)
			printf("height[%d]==%d  sa[%d]==%d\n",i,height[i],i,sa[i]);
		*/
		int flag=0;
		int l,r;
		for(i=1;i<=n;i++){
			int len=n-sa[i];
			for(j=height[i]+1;j<=len;j++){
				int cnt=Gao(i+1,n,j)-i+1;
				m-=cnt;
				if(m<=0){
					l=sa[i];r=sa[i]+j;
					flag=1;
					break;
				}
			}
			if(flag)break;	
		}
		for(i=l;i<r;i++)
			printf("%c",b[i]);
		puts("");
	}
	return 0;
}