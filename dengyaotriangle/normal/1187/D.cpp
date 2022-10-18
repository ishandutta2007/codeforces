#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int a[maxn],r[maxn];
vector<int> p[maxn];

int bit1[maxn],bit2[maxn];

void chgi(int i,int x){while(i<maxn)bit1[i]=max(bit1[i],x),i+=i&-i;}
void clri(int i){while(i<maxn)bit1[i]=INT_MIN,i+=i&-i;}
int qryi(int i){int ret=INT_MIN;while(i)ret=max(ret,bit1[i]),i-=i&-i;return ret;}
void chgx(int i,int x){while(i<maxn)bit2[i]=min(bit2[i],x),i+=i&-i;}
void clrx(int i){while(i<maxn)bit2[i]=INT_MAX,i+=i&-i;}
int qryx(int i){int ret=INT_MAX;while(i)ret=min(ret,bit2[i]),i-=i&-i;return ret;}
int mi[maxn],mx[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)p[i].clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){int x;cin>>x;p[x].push_back(i);}
        bool ok=1;
        for(int i=n;i>=1;i--){
            if(p[a[i]].empty()){ok=0;break;}
            r[i]=p[a[i]].back();p[a[i]].pop_back();
        }
        if(ok){
            for(int i=1;i<=n;i++)clri(i),clrx(i);
            for(int i=1;i<=n;i++){
                int v=qryx(n-r[i]+1);
                if(v<a[i])ok=0;
                chgx(n-r[i]+1,a[i]);
            }
            for(int i=n;i>=1;i--){
                int v=qryi(r[i]);
                if(v>a[i])ok=0;
                chgi(r[i],a[i]);
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}