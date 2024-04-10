#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=1005;
string a[maxn],b[maxn];
int n;
map<string,int> cnt;
string ans[maxn];
set<string> used;
bool fk[maxn];
int main(){
    read(n);
    rep(i,1,n){
    	cin>>a[i]>>b[i];
    	a[i]=a[i].substr(0,3);
    	b[i]=b[i].substr(0,1);
    	b[i]=a[i].substr(0,2)+b[i];
    }
    rep(i,1,n)cnt[a[i]]++;
    rep(i,1,n){
    	if(cnt[a[i]]>1){
    		if(used.count(b[i])){
    			puts("NO");return 0;
    		}used.insert(b[i]);
    		ans[i]=b[i];
    	}
    }
    for(;;){
    	bool flag=0;
    	rep(i,1,n){
    		if(cnt[a[i]]==1&&fk[i]==0){
    			if(used.count(a[i])+used.count(b[i])==2){
    				puts("NO");return 0;
    			}
    			if(used.count(a[i])+used.count(b[i])==1){
    				flag=1;
    				if(used.count(a[i]))ans[i]=b[i];
    				else ans[i]=a[i];
    				used.insert(ans[i]);fk[i]=1;
    			}
    		}
    	}
    	if(!flag)break;
    }
    rep(i,1,n)if(cnt[a[i]]==1&&fk[i]==0)ans[i]=a[i];
 	puts("YES");
    rep(i,1,n)cout<<ans[i]<<endl;
    return 0;
}