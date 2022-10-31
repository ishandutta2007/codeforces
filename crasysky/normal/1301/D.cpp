/*
#include <bits/stdc++.h>
using namespace std;
const int N=202,INF=1e9;
int c[N],cnt[N][N],mxs[N][N],mns[N][N];
char s[1000006];
void add(int mx,int mn,int t){
    cnt[mx][mn]+=t;
    mxs[mx][mn]=max(mxs[mx][mn],cnt[mx][mn]-mns[mx][mn]);
    mns[mx][mn]=min(mns[mx][mn],cnt[mx][mn]);
}
int main(){
    int n; scanf("%d%s",&n,s);
    for (int mx='a';mx<='z';++mx)
        for (int mn='a';mn<='z';++mn)
            mxs[mx][mn]=-INF,mns[mx][mn]=INF;
    for (int i=1;i<=n;++i){
        ++c[s[i]];
        for (int mx='a';mx<='z';++mx) add(mx,s[i],-1);
        for (int mn='a';mn<='z';++mn) add(s[i],mn,1);
    }
    int ans=-INF;
    for (int mx='a';mx<='z';++mx)
        for (int mn='a';mn<='z';++mn)
            if (mxs[mx][mn]&&c[mx]&&c[mn]){
                ans=max(ans,mxs[mx][mn]);
                if (mxs[mx][mn]==5) cout<<mx<<" "<<mn<<endl;
            }
    cout<<ans<<endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int N=3003;
int k,cnt,a[N];
string s[N];
void add(string str,int c){
    if (!k) return;
    int n=str.length();
    if (min(c,k/n))
        s[++cnt]=str,a[cnt]=min(c,k/n),k-=a[cnt]*n,c-=a[cnt];
    if (c&&k){
        a[++cnt]=1;
        for (int i=0;i<k;++i) s[cnt]=s[cnt]+str[i];
        k=0;
    }
}
int main(){
    int n,m; cin>>n>>m>>k;
    if (k>4*n*m-2*n-2*m){ cout<<"NO"<<endl; return 0; }
    cout<<"YES"<<endl;
    if (n==1) add("R",m-1),add("L",m-1);
    else if (m==1) add("D",n-1),add("U",n-1);
    else if (m==2){
        add("RDL",1),add("RULD",1);
        for (int i=1;i<=n-2;++i) add("DRU",1),add("DL",1);
        add("U",n-1);
    }
    else{
        add("R",m-1),add("DLU",1),add("DRUL",1);
        for (int i=1;i<=m-3;++i) add("LDR",1),add("LU",1);
        add("LDRL",1);
        for (int i=1;i<=n-2;++i) add("D",1),add("RUD",m-1),add("L",m-1);
        add("U",n-1);
    }
    cout<<cnt<<endl;
    for (int i=1;i<=cnt;++i) cout<<a[i]<<" "<<s[i]<<endl;
    return 0;
}