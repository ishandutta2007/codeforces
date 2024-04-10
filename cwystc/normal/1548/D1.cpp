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

int cnt[5][5],n,x[500010],y[500010];
LL ans;

int cal(int p,int q){
    int X=x[p]-x[q];
    int Y=y[p]-y[q];
    if (X%4==0 && Y%4==0) return 0;
    else return 2;
}

int CAL(int X,int Y){
    if (X%4==0 && Y%4==0) return 0;
    else return 2;
}

int main(){
    cin>>n;
    FOR(i,1,n) getint(x[i]),getint(y[i]);
    /*
    FOR(i,1,n)
        FOR(j,i+1,n)
            FOR(k,j+1,n){
                if((cal(i,j)+cal(j,k)+cal(k,i))%4==0) ++ans;
            }
    */
    FOR(i,1,n) ++cnt[((x[i]%4+4)%4)/2][((y[i]%4+4)%4)/2];
    FOR(i,1,n)
        FOR(j,i+1,n){
            FOR(p,0,1)
                FOR(q,0,1){
                    if ((cal(i,j)+CAL(p*2-x[i],q*2-y[i]) + CAL(p*2-x[j],q*2-y[j]))%4!=0) continue;
                    int t=cnt[p][q];
                    if (((x[i]%4+4)%4)/2==p && ((y[i]%4+4)%4)/2==q) --t;
                    if (((x[j]%4+4)%4)/2==p && ((y[j]%4+4)%4)/2==q) --t;
                    ans+=t;
                }
        }
    cout<<ans/3<<endl;
	return 0;
}