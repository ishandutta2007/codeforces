    #include<bits/stdc++.h>
    #define LL long long
    #define pb push_back
    using namespace std;
    const int N=1010,M=4e5+50,K=2e4;
    vector<int>v;
    int n,k,b[K],mx,trs[20][N];LL f[N][K],sum[20][N],ans=-1e18;
    void cmax(LL &x,LL y){y>x?x=y:0;}
    int ch[N][14],cnt,val[N],fail[N],q[N],l,r;char s[M];
    void insert(int x){
    	int p=0;
    	for(int i=0,c;s[i];i++){
    		if(!ch[p][c=s[i]-'a'])ch[p][c]=++cnt;
    		p=ch[p][c];
    	}
    	val[p]+=x;
    }
    void build(){
    	for(int i=0;i<14;i++)if(ch[0][i])q[++r]=ch[0][i];l=1;
    	while(l<=r){
    		int x=q[l++];
    		for(int i=0;i<14;i++){
    			int &y=ch[x][i],z=ch[fail[x]][i];
    			if(y)fail[y]=z,val[y]+=val[z],q[++r]=y;
    			else y=z;
    		}
    	}
    }
    int main(){
    	scanf("%d",&k);
    	for(int i=1,x;i<=k;i++)scanf("%s%d",s,&x),insert(x);
    	build();scanf("%s",s+1);n=strlen(s+1);
    	for(int i=1;i<=n;i++)if(s[i]=='?')v.pb(i);v.pb(n+1);
    	memset(f,0xcf,sizeof(f));f[0][0]=0;mx=1<<14;
    	for(int i=0;i<mx;i++)b[i]=b[i>>1]+(i&1);
    	for(int i=0;i<=cnt;i++)for(int j=0;j<v.size();j++){
    		int l=i;LL ss=0;
    		for(int k=j?v[j-1]+1:1;k<v[j];k++)l=ch[l][s[k]-'a'],ss+=val[l];
    		trs[j][i]=l;sum[j][i]=ss;
    	}
    	for(int i=0;i<mx;i++){
    		if(b[i]>=v.size()-1)continue;
    		for(int j=0;j<=cnt;j++)
    			for(int k=0;k<14;k++)
    				if(!(i>>k&1)){
    					int to=ch[trs[b[i]][j]][k];
    					cmax(f[to][i|1<<k],f[j][i]+sum[b[i]][j]+val[to]);
    				}
    	}
    	for(int i=0;i<mx;i++)if(b[i]==v.size()-1)for(int j=0;j<=cnt;j++)cmax(ans,f[j][i]+sum[b[i]][j]);
    	cout<<ans;
    	return 0;
    }