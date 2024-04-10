/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=500005;
int T,n,a[N];
set<pii> st;
int zero,two,flag=1,tag=0;
void insert(int l,int r){
    if(l>r) return;
    if(flag==1) st.insert(mk(l-tag,r-tag));
    else st.insert(mk(tag-r,tag-l));
}
// void print(){
//     printf("st:\n");
//     outln(sz(st));
//     for(auto &u : st) printf("%d %d\n",u.first*flag+tag,u.second*flag+tag);
//     puts("");
// }
vector<pii> used;
void solve(){
    st.clear(); two=-1; zero=0; flag=1; tag=0;
    for(int i=1;i<=n;i++){
        if(two!=-1){
            st.clear(),zero+=2; flag=1; tag=0;
            if(a[i-1]-two<a[i]) st.insert(mk(a[i-1]-two,a[i-1]-two));
            two=-1;
        }
        else{
            if(!st.empty()){
                flag*=-1; tag=a[i-1]-tag;
                zero++;
                if(flag==1){
                    auto it=st.upper_bound(mk(a[i]-1-tag,inf)),it2=it;
                    used.clear();
                    while(it2!=st.end()) used.push_back(*it2),it2++;
                    if(it!=st.begin()){
                        it--;
                        if(it->second+tag>a[i]-1){
                            int tmp1=it->first;
                            st.erase(it);
                            insert(tmp1+tag,a[i]-1);
                        }
                    }
                    for(auto &u : used) st.erase(u);
                }
                else{
                    auto it=st.upper_bound(mk(tag+1-a[i],inf));
                    if(it!=st.begin()){
                        used.clear(); it--;
                        auto it2=it; it2--;
                        if(it!=st.begin()) while(true){
                            used.push_back(*it2); 
                            if(it2==st.begin()) break; it2--;
                        }
                        if(it!=st.end()&&-it->second+tag<=a[i]-1){
                            int tmp2=it->second;
                            st.erase(it);
                            insert(-tmp2+tag,a[i]-1);
                        }
                        if(it!=st.end()&&-it->second+tag>a[i]-1)
                            st.erase(it);
                        for(auto &u : used) st.erase(u);
                    }
                }
            }
            else{
                if(i!=1) insert(1,min(a[i-1],a[i])-1);
            }
        }
        if(a[i]%2==0&&!st.empty()){
            if(flag==1){
                auto it=st.upper_bound(mk(a[i]/2-tag,inf));
                if(it!=st.begin()){
                    it--;
                    if(it->second+tag>=a[i]/2){
                        two=a[i]/2;
                        int tmp1=it->first,tmp2=it->second;
                        st.erase(it);
                        insert(tmp1+tag,a[i]/2-1);
                        insert(a[i]/2+1,tmp2+tag);
                    }
                }
            }
            else{
                auto it=st.upper_bound(mk(tag-a[i]/2,inf));
                if(it!=st.begin()){
                    it--;
                    if(-it->second+tag<=a[i]/2){
                        two=a[i]/2;
                        int tmp1=it->first,tmp2=it->second;
                        st.erase(it);
                        insert(-tmp2+tag,a[i]/2-1);
                        insert(a[i]/2+1,-tmp1+tag);
                    }
                }
            }
        }
        if(two==-1&&a[i]%2==0) insert(a[i]/2,a[i]/2);
    }
    int ans=zero;
    if(two!=-1) ans+=2;
    else if(!st.empty()) ans++;
    cout<<n*2-ans<<endl;
}

signed main()
{
    T=read();
    while(T--){
        n=read(); for(int i=1;i<=n;i++) a[i]=read();
        solve();
    }
    return 0;
}