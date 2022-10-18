#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;
const int maxl=11;
const int dic=4;


int bit[maxl][dic][maxn];

int pl[maxl][maxl];

char _[maxn];
int s[maxn];
int n;
int qr[maxn],ql;

inline int lbt(int x){return x&(-x);}
inline void chg(int* bit,int i,int v){
    while(i<maxn){bit[i]+=v;i+=lbt(i);}
}
inline int qry(int* bit,int i){
    int ans=0;while(i){ans+=bit[i];i-=lbt(i);}
    return ans;
}

inline int cov(char p){
    switch(p){
        case 'A':return 0;
        case 'T':return 1;
        case 'C':return 2;
        case 'G':return 3;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>(_+1);
    n=strlen(_+1);
    for(int i=1;i<=n;i++){
        s[i]=cov(_[i]);
    }
    for(int i=1;i<maxl;i++){
        int c2=0;
        for(int j=1;j<=i;j++){
            pl[i][j-1]=c2+1;
            vector<pair<int,int> > tf;
            for(int k=j;k<=n;k+=i){
                tf.push_back(make_pair(++c2,k));
            }
            for(int k=0;k<dic;k++){
                for(int l=0;l<tf.size();l++){
                    if(s[tf[l].second]==k){
                        chg(bit[i][k],tf[l].first,1);
                    }
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x;char c;
            cin>>x>>c;
            int v=cov(c);
            for(int i=1;i<maxl;i++){
                int f=(x-1)%i;
                chg(bit[i][s[x]],pl[i][f]+(x-1)/i,-1);
                chg(bit[i][v],pl[i][f]+(x-1)/i,1);
            }
            s[x]=v;
        }else{
            int l,r;
            char f[maxl];
            cin>>l>>r>>f;
            ql=strlen(f);
            for(int i=0;i<ql;i++)qr[i]=cov(f[i]);
            int ans=0;
            for(int i=0;i<ql;i++){
                if(l+i>r)break;
                //cerr<<l<<','<<r<<','<<ql<<','<<(l+i-1)%ql<<','<<(r-1)/ql<<','<<(l-2)/ql<<endl;
                int md=(l+i-1)%ql;
                ans+=qry(bit[ql][qr[i]],pl[ql][md]+(r-md-1)/ql)-qry(bit[ql][qr[i]],pl[ql][md]+(l+i-1)/ql-1);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}