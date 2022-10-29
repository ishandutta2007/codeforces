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
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

int t = 1,n,m,k,q,L,l,r,a[100009],cnt[29],b,c,u,v,x,y,z,mod = 1e9 + 7;
string s;
struct st{int x,y;};

inline bool cmp(const st &a,const st &b){return a.x < b.x;}

void print(){
	for (int i = 1;i <= n;i += 1) cout<<char('a' + a[i]);
	puts("");
}

int main(){
	rd(t);
	while (t --){
		cin>>s,n = s.length(),fill(cnt,cnt + 26,0); int qwq = 0,max_ = 0;
		for (int i = 1;i <= n;i += 1) a[i] = s[i - 1] - 'a',qwq += cnt[a[i]] == 0,cnt[a[i]] += 1;
		bool wtf = 0;
		for (int i = 0;i < 26;i += 1) if (cnt[i] > 1){wtf = 1; break;}
		if (!wtf){
			sort(a + 1,a + n + 1);
			print();
			continue;
		}
		if (qwq == 1){cout<<s<<endl; continue;}
		else if (qwq >= 3){
			bool fl = 0;
			for (int i = 0;i < 26;i += 1){
				if (cnt[i] == 1){
					for (int j = 1;j <= n;j += 1){
						if (a[j] == i){
							swap(a[1],a[j]);
							sort(a + 2,a + n + 1);
							print();
							fl = 1; break;
						}
					}
					break; 
				}
			}
			if (fl) continue;
			sort(a + 1,a + n + 1);
			int pos1,pos2;
			for (int i = 1;i <= n;i += 1) if (a[i] != a[1]){pos1 = i; break;}
			for (int i = pos1;i <= n;i += 1) if (a[i] != a[pos1]){pos2 = i; break;}
			if (cnt[a[1]] > n - cnt[a[1]] + 2) swap(a[2],a[pos1]),swap(a[pos1 + 1],a[pos2]);
			else{
				for (int i = 3;i <= n;i += 2){
					if (a[i] != a[1]) break;
					swap(a[i],a[pos1 ++]);
				}
			} 
			print();
		}
		else{
			sort(a + 1,a + n + 1);
			int pos1;
			for (int i = 1;i <= n;i += 1) if (a[i] != a[1]){pos1 = i; break;}
			if (cnt[a[pos1]] == 1 && cnt[a[1]] > 1) swap(a[1],a[pos1]);
			else if (cnt[a[1]] > n - cnt[a[1]] + 2){
				swap(a[2],a[pos1]);
				sort(a + 1,a + n + 1,greater<ll>());
				swap(a[1],a[n - pos1 + 2]);
			}
			else{
				for (int i = 3;i <= n;i += 2){
					if (a[i] != a[1]) break;
					swap(a[i],a[pos1 ++]);
				}
			}
			print();
		}
	}
	return 0;
}