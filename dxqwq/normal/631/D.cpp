#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long nxt[200005];
long long n,m;
int len1=0,len2=0;
pair<long long,char> T[200005];
pair<long long,char> P[200005];
void getNext(pair<long long,char> P[])
{
	int i=0,j;
	j=nxt[0]=-1;
	while(i<len2){
		while(j!=-1&&P[i].second!=P[j].second)j=nxt[j];
		nxt[++i]=++j;
	}
}
int main(){
	long long ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%lld-%c",&T[len1].first,&T[len1].second);
		if(len1&&T[len1].second==T[len1-1].second) T[len1-1].first+=T[len1].first; else len1++;
	}
	for(int i=0; i<m; i++)
	{
		scanf("%lld-%c",&P[len2].first,&P[len2].second);
		if(len2&&P[len2].second==P[len2-1].second) P[len2-1].first+=P[len2].first;
		else len2++;
	}
	getNext(P);
	if(len2==1) for(int i=0; i<len1; i++) if(P[0].second==T[i].second&&P[0].first<=T[i].first) ans+=T[i].first-P[0].first+1ll;  
	else ans+=0; else if(len2==2) for(int i=0; i<len1; i++) if(P[0].second==T[i].second&&P[1].second==T[i+1].second&&P[0].first<=T[i].first&&P[1].first<=T[i+1].first) ans++; 
	else ans+=0; else
	{
		int i=0,j=0;
		while(i<len1-1)
		{  
        	if(j==-1||(T[i].second==P[j+1].second&&T[i].first==P[j+1].first)) ++i,++j; else j=nxt[j];  
        	if(j+1==len2-1) if(T[i-len2+1].second==P[0].second&&T[i].second==P[len2-1].second&&T[i-len2+1].first>=P[0].first&&T[i].first>=P[len2-1].first)ans++;  
    	}  
	}
	printf("%lld\n",ans);
}