        #include<bits/stdc++.h>
        #define pb push_back
        #define mp make_pair
        #define fi first
        #define se second
        #define SZ(x) ((int)x.size())
        #define FOR(i,a,b) for (int i=a;i<=b;++i)
        #define FORD(i,a,b) for (int i=a;i>=b;--i)
        using namespace std;
        typedef long long LL;
        typedef pair<int,int> pa;
        typedef vector<int> vec;
        void getint(int &v){
            char ch,fu=0;
            for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
            if(ch=='-') fu=1, ch=getchar();
            for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
            if(fu) v=-v;
        }
        map<int,int> M;
        LL b[500010];
        int n,f[500010],p[500010],pr,k,a[500010];
        LL ans;
        bool u[500010];
        void getp(){
        	FOR(i,2,100000){
        		if (!u[i]){p[++pr]=i;f[i]=i;}
        		FOR(j,1,pr){
        			if (i*p[j]>100000) break;
        			u[i*p[j]]=1;
        			if (i%p[j]==0){f[i*p[j]]=p[j];break;}
        			else f[i*p[j]]=p[j];
        		}
        	}
        }
        int main(){
        	cin>>n>>k;
        	FOR(i,1,n) getint(a[i]);
        	getp();
        	FOR(i,1,n){
        		int t=a[i];
        		a[i]=1;
        		b[i]=1;
        		while (t>1){
        			int h=f[t];
        			int cnt=0;
        			while (t%h==0) t/=h,++cnt;
        			cnt%=k;
        			FOR(j,1,cnt) a[i]=a[i]*h;
        			if (b[i]!=-1){
        				FOR(j,1,(k-cnt)%k){b[i]=b[i]*h;if (b[i]>100000){b[i]=-1;break;}}
        			}
        		}
        		
        	}
        	FOR(i,1,n){
        		if (M.find(b[i])!=M.end()) ans+=M[b[i]];
        		if (M.find(a[i])==M.end()) M[a[i]]=1; else ++M[a[i]];
        	}
        	cout<<ans<<endl;
        	return 0;
        }