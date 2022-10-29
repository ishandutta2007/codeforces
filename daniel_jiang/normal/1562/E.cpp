// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=5005;
int T,n,f[N];
string s;
struct LCP{
	int t1[N], t2[N], c[N],rank1[N], height[N],RMQ[N],qwq[N],best[20][N],r[N],sa[N];
	inline bool cmp(int *r, int a, int b, int l){
		return r[a] == r[b] && r[a + l] == r[b + l];
	}
	inline void da(int str[], int sa[], int rank1[], int height[], int n, int m){
		n++;
		int p, *x = t1, *y = t2;
		for (re i = 0; i < m; i++) c[i] = 0;
		for (re i = 0; i < n; i++) c[x[i] = str[i]]++;
		for (re i = 1; i < m; i++) c[i] += c[i - 1];
		for (re i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
		for (re j = 1; j <= n; j*=2){
			p = 0;
			for (re i = n - j; i < n; i++)
				y[p++] = i;
			for (re i = 0; i < n; i++)
				if (sa[i] >= j)
					y[p++] = sa[i] - j;
			for (re i = 0; i < m; i++)
				c[i] = 0;
			for (re i = 0; i < n; i++)
				c[x[y[i]]]++;
			for (re i = 1; i < m; i++)
				c[i] += c[i - 1];
			for (re i = n - 1; i >= 0; i--)
				sa[--c[x[y[i]]]] = y[i];
			swap(x, y);
			p = 1;
			x[sa[0]] = 0;
			for (re i = 1; i < n; i++)
				x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
			if (p >= n) break;
			m = p;
		}
		int k = 0;n--;
		for (re i = 0; i <= n; i++)
			rank1[sa[i]] = i;
		for (re i = 0; i < n; i++)
		{
			if (k)
				k--;
			int j = sa[rank1[i] - 1];
			while (str[i + k] == str[j + k])
				k++;
			height[rank1[i]] = k;
		}
	}
	inline void initRMQ(int n)
	{
		for (int i = 1; i <= n; i++)
			RMQ[i] = height[i];
		qwq[0] = -1;
		for (int i = 1; i <= n; i++)
			qwq[i] = ((i & (i - 1)) == 0) ? qwq[i - 1] + 1 : qwq[i - 1];
		for (int i = 1; i <= n; i++)
			best[0][i] = i;
		for (int i = 1; i <= qwq[n]; i++)
			for (int j = 1; j + (1 << i) - 1 <= n; j++){
				int a = best[i - 1][j];
				int b = best[i - 1][j + (1 << (i - 1))];
				if (RMQ[a] < RMQ[b]) best[i][j] = a;
				else best[i][j] = b;
			}
	}
	inline int askRMQ(int a, int b){
		int t = qwq[b - a + 1];
		b -= (1 << t) - 1;
		a = best[t][a]; b = best[t][b];
		return RMQ[a] < RMQ[b] ? a : b;
	}
	inline int lcp(int a, int b){
		a = rank1[a]; b = rank1[b];
		if (a > b)
			swap(a, b);
		return height[askRMQ(a + 1, b)];
	}
	inline void init(string s, int n){
		for(re i = 1; i <= n; i++)
			r[i - 1] = s[i] - 'a' + 1;
		r[n] = 0;
		da(r, sa, rank1, height, n, 128);
		initRMQ(n);
	}
}SA;


// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>s;s=" "+s;int ans=0;
		SA.init(s,n);
		for(re i=1;i<=n;++i){
			f[i]=n-i+1;
			for(re j=1;j<i;++j){
				int res=SA.lcp(j-1,i-1);
	//			cout<<i<<' '<<j<<' '<<res<<endl; 
				if(res!=n-i+1&&s[j+res]<s[i+res]) f[i]=max(f[i],f[j]+n-i+1-res);//,cout<<i<<' '<<j<<' '<<res<<endl;
			}
			ans=max(ans,f[i]);//cout<<i<<' '<<f[i]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

// ---------- Main ---------- //