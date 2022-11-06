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
char s[500010];
int a[500010],k,b[500010],n;
bool ok(){
	FOR(i,1,n) if (b[i]>a[i]) return 1;
	else if (b[i]<a[i]) return 0;
	return 1;
}
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	FOR(i,1,n) a[i]=s[i]-'0';
	FOR(i,1,n) if (i<=k) b[i]=a[i]; else b[i]=b[i-k];
	if (ok()){
		cout<<n<<endl;
		FOR(i,1,n) printf("%d",b[i]);
		return 0;
	}
	int t=k;
	++b[t];
	while (1){
		if (b[t]>9){
			b[t]=0;
			++b[t-1];
			--t;
			
		}
		else break;
	}
	FOR(i,k+1,n) b[i]=b[i-k];
	cout<<n<<endl;
		FOR(i,1,n) printf("%d",b[i]);
	return 0;
}