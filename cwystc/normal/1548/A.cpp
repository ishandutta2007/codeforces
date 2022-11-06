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

int n,m,s[500010],ans;

int main(){
    cin>>n>>m;
    FOR(i,1,m){
        int x,y;
        getint(x),getint(y);
        if (x>y) swap(x,y);
        s[x]++;
    }
    FOR(i,1,n) if (s[i]==0) ++ans;
    cin>>m;
    while (m--){
        int x,y,tp;
        getint(tp);
        if (tp==3){
            printf("%d\n",ans);
            continue;
        }
        getint(x),getint(y);
        if (x>y) swap(x,y);
        if (tp==1){
            if (s[x]==0) --ans;
            ++s[x];
            
        }
        else{
            --s[x];
            if (s[x]==0) ++ans;
        }
    }
	return 0;
}