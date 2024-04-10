#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

#define gc getchar
#define pc putchar
template <typename T> T scani(T &n){n = 0;bool negative = false;char c = gc();while( c < '0' || c > '9'){if(c == '-') negative = true;c = gc();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = gc();}if(negative) n = ~(n-1);return n;}
int scans(char *a){int i=0;char c = 0;while(c < 33) c = gc();while(c > 33){a[i++] = c;c = gc();}a[i] = 0;return i;}
template <typename T> void write(T n,int type = true){if(n<0) {pc('-');n = -n;}if(!n) {pc('0');if(type==32) pc(' '); else if(type) pc('\n'); return;}char buff[22];int len = 0;while(n) buff[len++] = n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);if(type==32) pc(' '); else if(type) pc('\n');}


int f[10000009],input[10000009],sv[10000009];
void solve(){
    int n;scani(n);
    for(int i=1;i<=n;i++){
        int t;scani(t);
    	input[t]++;
    }
    sv[1]=1;
    for(int i=2;i<10000002;i++){
    	if(sv[i]==0){
            f[i]+=input[i];
    		for(int j=2*i;j<10000002;j+=i){
    			sv[j]=1;f[i]+=input[j];
    		}
    	}
    }
    for(int i=2;i<10000002;i++){
        f[i]+=f[i-1];
    }
    int m,l,r;scani(m);
    for(int i=0;i<m;i++){
        scani(l);scani(r);
        if(r>10000001)r=10000001;if(l>10000001)l=10000001;if(l<1)l=1;
        write(f[r]-f[l-1]);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}