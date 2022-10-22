

    //Code By CXY
    #include<bits/stdc++.h>
    using namespace std;
     
    #define min _______min
    #define max _______max
     
    const int MAXN = 3e5 + 10;
    const int INF = 1e9;
     
    int n,m,ans1,ans2;
    int a[MAXN][10],p[MAXN][10],c[MAXN],rev[MAXN]; 
    int l = INF,r = -1,mid;
    int buk[510];
     
    inline int min(int x,int y) {return (x < y) ? x : y;}
    inline int max(int x,int y) {return (x > y) ? x : y;}
     
    bool find(int x,int p) {
    	bool res = false;
    	if(p < 0) {
    		if(buk[x]) ans2 = buk[x];
    		return buk[x];
    	}
    	if(x & (1 << p)) return find(x,p - 1);
    	res |= find(x,p - 1);
    	res |= find(x + (1 << p),p - 1);
    	return res;
    }
     
    inline bool chk() {
    	memset(buk,0,sizeof buk);
    	for(register int i = 1;i <= n; ++i) {
    		int now = 0;
    		for(register int j = 1;j <= m; ++j) {
    			now <<= 1;
    			if(a[i][j] >= mid) now++;
    		}
    		buk[now] = i;
    		c[i] = now;
    		if(c[i] == (1 << m) - 1) {ans1 = ans2 = i; return true;}
    		rev[i] = ((1 << m) - 1) ^ c[i];
    	}
    	for(register int i = 1;i <= n; ++i) 
    		if(find(rev[i],7)) {
    			ans1 = i;
    			return true;
    		}
    	return false;
    }
     
    int main () {
    	scanf("%d%d",&n,&m);
    	for(register int i = 1;i <= n; ++i)
    		for(register int j = 1;j <= m; ++j) {
    			scanf("%d",&a[i][j]);
    			l = min(l,a[i][j]);
    			r = max(r,a[i][j]);
    		}
    	while(l < r) {
    		mid = (l + r + 1) >> 1;
    		if(chk()) l = mid;
    		else r = mid - 1;
    	}
		if(ans1 == 0 && ans2 == 0) printf("1 1 \n");
		else printf("%d %d",min(ans1,ans2),max(ans1,ans2));
    	return 0;
    }