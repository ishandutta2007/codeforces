#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 100001
#define M 600001
#define K 2000000
struct Edge{
	int End;
	char Tag;
};
I Edge Pair(int y,char c){
	Edge Res;
	Res.End=y;
	Res.Tag=c;
	return Res;
}
vector<Edge>G[N];
int h[N],f[N],sz[N],pos[N],Top[N],dep[N],PosU[N],PosD[N],rk[M],sa[M],hei[M],col[M],g[20][M];
char s[M],fe[N];
I void PreDFS(int x,int F){
	f[x]=F;
	dep[x]=dep[F]+1;
	sz[x]=1;
	for(Edge T:G[x]){
		int v=T.End;
		if(v!=F){
			fe[v]=T.Tag;
			PreDFS(v,x);
			sz[x]+=sz[v];
			if(sz[v]>sz[h[x]]){
				h[x]=v;
			}
		}
	}
}
I void ReDFS(int x,int t){
	Top[x]=t;
	if(h[x]!=0){
		ReDFS(h[x],t);
		for(Edge T:G[x]){
			int v=T.End;
			if(v!=f[x]&&v!=h[x]){
				ReDFS(v,v);
			}
		}
	}
}
I void BuildSA(const int n){
	static int ct[M],temrk[M],sa2[M];
	for(R i=1;i<=n;i++){
		ct[s[i]-'a']++;
	}
	for(R i=1;i!=27;i++){
		ct[i]+=ct[i-1];
	}
	for(R i=1;i<=n;i++){
		sa[ct[s[i]-'a']]=i;
		ct[s[i]-'a']--;
	}
	int sum=0,cur,*rk1=rk,*rk2=temrk;
	for(R i=1;i<=n;i++){
		if(s[sa[i]]!=s[sa[i-1]]){
			sum++;
		}
		rk[sa[i]]=sum;
	}
	for(R i=1;sum!=n;i<<=1){
		for(R j=0;j!=i;j++){
			sa2[j+1]=n-j;
		}
		cur=i;
		for(R j=1;j<=n;j++){
			if(sa[j]>i){
				cur++;
				sa2[cur]=sa[j]-i;
			}
		}
		for(R j=0;j<=sum;j++){
			ct[j]=0;
		}
		for(R j=1;j<=n;j++){
			ct[rk1[j]]++;
		}
		for(R j=1;j<=sum;j++){
			ct[j]+=ct[j-1];
		}
		for(R j=n;j!=0;j--){
			int&c=ct[rk1[sa2[j]]];
			sa[c]=sa2[j];
			c--;
		}
		sum=0;
		for(R j=1;j<=n;j++){
			if(rk1[sa[j]]!=rk1[sa[j-1]]||(sa[j]+i>n?0:rk1[sa[j]+i])!=(sa[j-1]+i>n?0:rk1[sa[j-1]+i])){
				sum++;
			}
			rk2[sa[j]]=sum;
		}
		int*t=rk1;
		rk1=rk2;
		rk2=t;
	}
	if(rk1!=rk){
		for(R i=1;i<=n;i++){
			rk[i]=rk1[i];
		}
	}
	cur=0;
	for(R i=1;i<=n;i++){
		if(cur!=0){
			cur--;
		}
		if(rk[i]!=1){
			int pos=sa[rk[i]-1];
			while(i+cur<=n&&pos+cur<=n&&s[i+cur]==s[pos+cur]){
				cur++;
			}
			hei[rk[i]]=cur;
		}
	}
}
namespace SEG{
	int Root[M],Ls[K],Rs[K],Sum[K],Tot,Len;
	I void Init(const int m){
		Len=m;
	}
	I void GetNode(int&x){
		Tot++;
		x=Tot;
	}
	I void Insert(int p1,int p2,int lf,int rt,const int x){
		Sum[p2]=Sum[p1]+1;
		if(lf!=rt){
			int mid=lf+rt>>1;
			if(x>mid){
				GetNode(Rs[p2]);
				Ls[p2]=Ls[p1];
				Insert(Rs[p1],Rs[p2],mid+1,rt,x);
			}else{
				GetNode(Ls[p2]);
				Rs[p2]=Rs[p1];
				Insert(Ls[p1],Ls[p2],lf,mid,x);
			}
		}
	}
	I void Append(int x,int c){
		if(c==0){
			Root[x]=Root[x-1];
		}else{
			GetNode(Root[x]);
			Insert(Root[x-1],Root[x],1,Len,c);
		}
	}
	I int GetAns(int p1,int p2,int lf,int rt,const int l,const int r){
		if(l<=lf&&rt<=r){
			return Sum[p2]-Sum[p1];
		}
		int mid=lf+rt>>1,res=0;
		if(l<=mid){
			res=GetAns(Ls[p1],Ls[p2],lf,mid,l,r);
		}
		if(r>mid){
			res+=GetAns(Rs[p1],Rs[p2],mid+1,rt,l,r);
		}
		return res;
	}
	I int GetSum(int l,int r,int ql,int qr){
		return GetAns(Root[l-1],Root[r],1,Len,ql,qr);
	}
}
int main(){
	//freopen("1.in","w",stdout);
	int n,m,q,x,y,totlen=-1,len,ql,qr,l,r,cl,cr;
	scanf("%d%d%d",&n,&m,&q);
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		char c;
		scanf(" %c",&c);
		G[x].push_back(Pair(y,c));
		G[y].push_back(Pair(x,c));
	}
	PreDFS(1,0);
	ReDFS(1,1);
	/*puts("");
	for(R i=2;i<=n;i++){
		putchar(fe[i]);
	}
	puts("\n");*/
	for(R i=1;i<=m;i++){
		totlen++;
		s[totlen]='{';
		pos[i]=totlen+1;
		scanf("%s",s+pos[i]);
		len=strlen(s+pos[i]);
		for(R j=1;j<=len;j++){
			col[totlen+j]=i;
		}
		totlen+=len;
	}
	for(R i=2;i<=n;i++){
		if(G[i].size()==1){
			//printf("I%d %d\n",i,Top[i]);
			totlen++;
			s[totlen]='{';
			y=f[Top[i]];
			for(R j=i;j!=y;j=f[j]){
				if(j!=1){
					totlen++;
					PosU[j]=totlen;
					s[totlen]=fe[j];
				}
			}
			totlen++;
			s[totlen]='{';
			for(R j=Top[i];j!=0;j=h[j]){
				if(j!=1){
					totlen++;
					PosD[j]=totlen;
					s[totlen]=fe[j];
				}
			}
		}
	}
	BuildSA(totlen);
	for(R i=1;i!=totlen;i++){
		g[0][i]=hei[i+1];
	}
	for(R i=1;1<<i<totlen;i++){
		for(R j=1;j<=totlen-(1<<i);j++){
			x=g[i-1][j];
			y=g[i-1][j+(1<<i-1)];
			g[i][j]=x<y?x:y;
		}
	}
	SEG::Init(m);
	for(R i=1;i<=totlen;i++){
		SEG::Append(i,col[sa[i]]);
	}
	/*printf("T%d\n",totlen);
	puts(s+1);
	for(R i=1;i<=totlen;i++){
		printf("%2d ",sa[i]);
	}
	puts("");
	for(R i=1;i<=totlen;i++){
		printf("%2d ",rk[i]);
	}
	puts("");
	for(R i=1;i<=totlen;i++){
		printf("%2d ",hei[i]);
	}
	puts("");*/
	for(R i=0;i!=q;i++){
		scanf("%d%d%d%d",&x,&y,&ql,&qr);
		vector<pair<int,int>>Up,Down,Sub;
		while(Top[x]!=Top[y]){
			if(dep[Top[x]]>dep[Top[y]]){
				Up.push_back(make_pair(x,Top[x]));
				x=f[Top[x]];
			}else{
				Down.push_back(make_pair(y,Top[y]));
				y=f[Top[y]];
			}
		}
		if(dep[x]>dep[y]){
			Up.push_back(make_pair(x,h[y]));
		}else if(dep[x]<dep[y]){
			Down.push_back(make_pair(y,h[x]));
		}
		for(auto T:Up){
			Sub.push_back(make_pair(rk[PosU[T.first]],dep[T.first]-dep[T.second]+1));
		}
		for(auto T=Down.rbegin();T!=Down.rend();T++){
			Sub.push_back(make_pair(rk[PosD[T->second]],dep[T->first]-dep[T->second]+1));
		}
		l=1;
		r=totlen;
		len=0;
		/*for(auto T:Sub){
			printf("T%d %d\n",T.first,T.second);
		}*/
		for(auto T=Sub.begin();T!=Sub.end()&&l<=r;T++){
			cl=cr=T->first;
			for(R j=19;j!=-1;j--){
				if(cl>=1<<j&&g[j][cl-(1<<j)]>=T->second){
					cl-=1<<j;
				}
				if(cr+(1<<j)<=totlen&&g[j][cr]>=T->second){
					cr+=1<<j;
				}
			}
			//printf("C%d %d\n",cl,cr);
			int l2=l,r2=r,mid,res=M;
			while(l2<=r2){
				mid=l2+r2>>1;
				int tem=rk[sa[mid]+len];
				if(tem<cl){
					l2=mid+1;
				}else{
					res=mid;
					r2=mid-1;
				}
			}
			l=l2=res;
			r2=r;
			res=0;
			while(l2<=r2){
				mid=l2+r2>>1;
				int tem=rk[sa[mid]+len];
				if(tem>cr){
					r2=mid-1;
				}else{
					res=mid;
					l2=mid+1;
				}
			}
			r=res;
			len+=T->second;
		}
		//printf("L%d %d\n",l,r);
		if(l>r){
			puts("0");
		}else{
			printf("%d\n",SEG::GetSum(l,r,ql,qr));
		}
	}
	return 0;
}